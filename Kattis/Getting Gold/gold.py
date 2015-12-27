import queue
num_columns, num_rows = map(int, input().split())
grid = []
danger_cells_grid = []
visited_cells_grid = []
position_start = None
for i in range(num_rows):
	grid.append(list(input()))

def is_surrounding_cell_a_trap(position):
	row = position[0]
	col = position[1]
	if row > 0 and grid[row - 1][col] == 'T':
		return True
	if col > 0 and grid[row][col - 1] == 'T':
		return True
	if col < (num_columns - 1) and grid[row][col + 1] == 'T':
		return True
	if row < (num_rows - 1) and grid[row + 1][col] == 'T':
		return True
	return False

for i in range(num_rows):
	visited_cells_grid.append([])
	for j in range(num_columns):
		if grid[i][j] == 'P':
			position_start = (i, j)
		visited_cells_grid[i].append(0)

q = queue.Queue()
q.put(position_start)

def insert_surrounding_elements_into_queue(pos):
	row = pos[0]
	col = pos[1]
	movement_x = [0, 0, 1, -1]
	movement_y = [1, -1, 0, 0]
	for i in range(4):
		row_new = row + movement_x[i]
		col_new = col + movement_y[i]
		if not ((visited_cells_grid[row_new][col_new] == 1) or (grid[row_new][col_new] == '#')):
			q.put((row_new, col_new))

gold = 0

while not q.empty():
	position = q.get()
	if visited_cells_grid[position[0]][position[1]] == 1:
		continue
	if grid[position[0]][position[1]] == 'G':
		gold = gold + 1
	visited_cells_grid[position[0]][position[1]] = 1
	if not is_surrounding_cell_a_trap(position):
		insert_surrounding_elements_into_queue(position)

print(gold)