file = File.open(ARGV[0])

n = file.gets.chomp.to_i

n.times do |turn|
  snappers, snaps = file.gets.chomp.split(' ').map(&:to_i)
  ans = ((snaps + 1.0)/(2**snappers) % 1).zero?
  ans = ans ? "ON" : "OFF" 
  puts "Case \##{turn+1}: #{ans}"
end

