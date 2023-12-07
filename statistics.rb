require "narray"

puts "science score :"
p science = [65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 25, 85, 46, 42, 78, 62, 84, 70]
puts "english score :"
p english = [44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84]

scie_ave = science.sum.fdiv(science.length)
eng_ave = english.sum.fdiv(english.length)