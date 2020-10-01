#collect arguments
dst = case(ARGV.size)
    when 0
        "hotmelted.c"
    when 1
        ARGV[0]
    else
        ARGV[0]
end

prefix = "#include \"mbed.h\"\n\n"

#read files in correct order
order = [
    /Defs/,
    /Utils/,
    /Params/,
    /Packer/,
    /Parser/,
    /Buffer/,
    /Filter/,
    /Digital/,
    /Timer/,
    /LED/,
    /UI/,
    /AnalogHardware/,
    /AnalogModel/,
    /AnalogConductor/,
    /Sampler/,
    /Trigger/,
    /Capture/,
    /UARTDriver/,
    /USBDriver/,
    /CommandConductor/,
    /CommandHardware/,
    /CommandHandlers/,
    /Executor/,
    /Main/,
]

files = [ "inc/Defs.h" ] +
        Dir["src/*.h"].sort{|a,b| order.find_index{|o| o =~ a} <=> order.find_index{|o| o =~ b}} +
        Dir["src/*.c"].sort{|a,b| order.find_index{|o| o =~ a} <=> order.find_index{|o| o =~ b}}

File.open(dst,'w') do |f|

    f << prefix

    files.each do |ff|
        puts "Processing #{ff}..."

        #strip out pragmas and includes
        lines = File.readlines(ff)
        lines.reject!{|l| l =~ /\#include/}
        lines.reject!{|l| l =~ /\#pragma/}

        #rename LED enum names
        lines.map!{|l| l.gsub(/(LED\d)/,"MY_\\1") }

        #find all static variables and prepend module name
        module_prefix = File.basename(ff,'.c') + "_"
        statics = lines.select{|l| l =~ /^(?:(?:static)|(?:STATIC))\s+(?:\w+)\s+(\w+)(?:\s*[=\[\;])/ }.map {|l| l =~ /(?:(?:static)|(?:STATIC))\s+(?:\w+)\s+(\w+)(?:\s*[=\[\;])/; [$1, module_prefix + $1] }

        #replace the static variable names with the prepended module name
        statics.each do |v|
            lines.map!{|l| l.gsub(/(\W)#{v[0]}(\W)/, "\\1#{v[1]}\\2")}
        end

        #write this file to splatted file
        f << lines.join
    end
end
