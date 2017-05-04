#!/usr/bin/python

import sys

if (len(sys.argv) > 1):
	file = open(sys.argv[1],"rb")
	data = file.read()
	data = bytearray(data)
	file.close()

	#for i in range(0, 155):
	#	print int(data[i])

	width = int(data[18])
	print width
	end = len(data)
	print end
	res = []
	start = end % (width * 3)
	while start < end:
		res.append([])
		i = start
		while i < start + width * 3:
			res[-1].append(data[i] + data[i + 1] + data[i + 2] - 10)
			i += 3
		start += width * 3
	with open('res.fdf', 'w') as f:
		for elt in reversed(res):
			for elt2 in reversed(elt):
				f.write(str(elt2) + " ")
			f.write("\n")
