import sys

def get_prefix_array(len_pattern, pattern):
	if pattern == '':
		return []
	prefix_array = []
	i = 0
	j = 1
	prefix_array.append(0)
	while j < len_pattern:
		if pattern[j] == pattern[i]:
			prefix_array.append(prefix_array[j - 1] + 1)
			i = i + 1
		elif i == 0:
			prefix_array.append(0)
		else:
			while True:
				i = prefix_array[i - 1]
				if (pattern[i] == pattern[j]) or (i == 0):
					break
			if pattern[i] != pattern[j]:
				prefix_array.append(0)
			else:
				prefix_array.append(prefix_array[i] + 1)
				i = i + 1
		j = j + 1
	return prefix_array

def search_pattern(len_pattern, text, pattern):
	list_indices_matches_start = []
	m = 0
	arr = get_prefix_array(len_pattern, pattern)
	# print arr
	i = 0
	while i < len(text):
		if text[i] == pattern[i - m]:
			i = i + 1
			if (i - m) == len_pattern:
				list_indices_matches_start.append(m)
				m = m + 1
				i = m
		else:
			while (text[i] != pattern[i - m]) and (m != i):
				index = i - m - 1
				m = i - arr[index]
			if text[i] != pattern[i - m]:
				m = m + 1
				i = i + 1
	return list_indices_matches_start

if __name__ == "__main__":
	count = 0
	len_pattern = None
	pattern = None
	text = None
	for line in sys.stdin:
		count = count + 1
		rem = count % 3
		if rem == 1:
			len_pattern = int(line)
		elif rem == 2:
			pattern = str(line)
		else:
			text = str(line)
			list_indices = search_pattern(len_pattern, text, pattern)
			if len(list_indices) == 0:
				print
			else:
				for index in list_indices:
					print index