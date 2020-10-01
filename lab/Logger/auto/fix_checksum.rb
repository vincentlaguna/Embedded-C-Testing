#collect arguments
src, dst = case(ARGV.size)
    when 0
        puts "You must supply a file to be updated, then optionally a new file to output"
        puts "For your entertainment: a self test..."
        [ "TEST", "TEST" ]
    when 1
        puts "writing to same file we read from"
        [ ARGV[0], ARGV[0] ]
    else
        [ ARGV[0], ARGV[1] ]
end

#if elf, convert to bin first
if (src =~ /\.elf/)
    newsrc = src.gsub(/\.elf/,'.bin')
   `arm-none-eabi-objcopy -O binary #{src} #{newsrc}`
   src = newsrc
end

#read vector table from file
orig = if (src == "TEST")
    "\x01\x00\x00\x00" +
    "\x02\x00\x00\x00" +
    "\x03\x00\x00\x00" +
    "\x04\x00\x00\x00" +
    "\x05\x00\x00\x00" +
    "\x06\x00\x00\x00" +
    "\x07\x00\x00\x00" +
    "\x08\x00\x00\x00" +
    "\x09\x00\x00\x00" +
    "\x0A\x00\x00\x00" +
    "\x0B\x00\x00\x00"
else
    File.open(src,'rb') { |f| orig = f.read }
    orig
end
all = orig.clone

#calculate the "checksum" over the first 7 vectors as 2's complement of sum of first 7 dwords
vectors = all.unpack('IIIIIII')
crc = vectors.inject(0) {|val, crc| crc + val }
crc = 0xFFFFFFFF & ((0xFFFFFFFF & (~crc)) + 1)

#replace the 8th vector with the CRC
bytes = [crc].pack('I')
4.times {|i| all[0x1C+i] = bytes[i] }

#write the new file with the updated checksum
if (dst == "TEST")
    puts orig.unpack("c*").map{|v| "0x" + v.to_s(16)}.join(" ")
    puts "\n"
    puts all.unpack("c*").map{|v| "0x" + v.to_s(16)}.join(" ")
else
    File.open(dst, 'wb') {|f| f << all }
end

