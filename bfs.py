def backtrace(parent, start, end):
    path = [end]
    while path[-1] != start:
        path.append(parent[path[-1]])
    path.reverse()
    return path

def bfs(graph, start, end):
    parent = {}
    queue = []
    queue.append(start)
    while queue:
        node = queue.pop(0)
        if node == end:
            return backtrace(parent, start, end)
        for adjacent in graph.get(node, []):
            parent[adjacent] = node # <<<<< record its parent 
            queue.append(adjacent)


a, b = list(map(int, raw_input().split(" ")))
# a ,b = int(a), int(b)

graph = {}
for i in xrange(b):
	type_, u, v = list(map(int, raw_input().split(" ")))
	if type_ == 1:
		try:
			graph[u].append(b)
		except:
			graph[u] = [b]

	elif type_ == 2:
		print len(bfs(graph, u, v))
