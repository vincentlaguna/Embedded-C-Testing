src = "build/release/unit4.bin"
dst = "build/release/unit4_crc.bin"

uno = ""
dos = ""
File.open(src,'rb') { |f| uno = f.read }
File.open(dst,'rb') { |f| dos = f.read }

File.open("auto/uno.txt",'w')  do |f|
  uno.unpack("C*").map{|v| "0x" + v.to_s(16).rjust(2,'0') }.each_slice(16){|a| f << a.join(" ") << "\n"}
end

File.open("auto/dos.txt",'w') do |f|
  dos.unpack("C*").map{|v| "0x" + v.to_s(16).rjust(2,'0') }.each_slice(16){|a| f << a.join(" ") << "\n"}
end
