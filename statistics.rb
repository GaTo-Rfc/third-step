puts "science score :"
p science = [65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 25, 85, 46, 42, 78, 62, 84, 70]
puts "english score :"
p english = [44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84]

# 平均
scie_ave = science.sum.fdiv(science.length)
eng_ave = english.sum.fdiv(english.length)
puts "理科平均点 : #{scie_ave}"
puts "英語平均点 : #{eng_ave}"

# 標準偏差
stddev_pre = science.map{|x| (x - scie_ave) ** 2}
scie_stddev = Math.sqrt(stddev_pre.sum / science.length).round(2)

stddev_pre = english.map{|x| (x - eng_ave) ** 2}
eng_stddev = Math.sqrt(stddev_pre.sum / english.length).round(2)

puts "理科標準偏差 : #{scie_stddev}"
puts "英語標準偏差 : #{eng_stddev}"

# 合計点
puts "理科合計点 : #{science.sum}"
puts "英語合計点 : #{english.sum}"

# 偏差値


# 並べ替え
puts "science sort score :"
p science.sort.reverse
puts "english sort score :"
p english.sort.reverse
