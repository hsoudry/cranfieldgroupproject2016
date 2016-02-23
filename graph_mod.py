from graph_tool.all import *
import numpy
import time
import matplotlib

def get_graph_from_file(path, progress=True):
	if progress==True:
		start = time.time()
		f = open(path)

		header = (f.readline()).split()
		n_nodes = int(header[0])
		n_edges = int(header[1])
		g = Graph(directed=False)
		nodes = g.add_vertex(n_nodes)
		for i in range(n_nodes):
	
			line = (f.readline()).split()
			
			print(str(i)+ " of "+str(n_nodes)+" nodes added")
			for j in range(len(line)):
		
				el = int(line[j])
				if(el > i):
					g.add_edge(g.vertex(i), g.vertex(el-1))
		end = time.time()

		print("time elapsed: " + str(end - start))
		return g
	else:
		f = open(path)
		header = (f.readline()).split()
		n_nodes = int(header[0])
		n_edges = int(header[1])
		g = Graph(directed=False)
		nodes = g.add_vertex(n_nodes)
		for i in range(n_nodes):
	
			line = (f.readline()).split()
					
			for j in range(len(line)):
		
				el = int(line[j])
				if(el > i):
					g.add_edge(g.vertex(i), g.vertex(el-1))
		
		return g


def calculate_pos(g, path = None):
	start = time.time()
	pos = sfdp_layout(g)
	end = time.time()
	print("time elapsed (calculating pos): " + str(end - start))
	if path!=None:
		list = [0,1]
		array1 = pos.get_2d_array(list)
		array1.tofile(path)
	return pos

def get_pos_from_file(g, path):
	array = numpy.fromfile(path)
	array = array.reshape((2,array.size/2))		
	pos = g.new_vertex_property("vector<double>")
	pos.set_2d_array(array)
	return pos


def get_v_part(v_path):
	f = open(v_path)

	result = []
	for line in f:
		result.append(float(line))

	return result



def draw_from_raw_file(f_path, d_path = None, g_path = None, progress = True):
	start = time.time()
	g = get_graph_from_file(f_path, progress)
	'''print("graph loaded, calculating nodes positions...")	
	pos = calculate_pos(g)
	
	if(g_path!=None):
		print("Saving graph to file(vertex positions included ! )...")
		g_path = g_path+".xml.gz"
		g.vertex_properties["pos"] = pos
		g.save(g_path)
	'''
	if (d_path ==None):
		print("drawing graph on screen using graphviz...")
		graphviz_draw(g, vsize = 0.01, penwidth= 0.1)
	else:
		print("drawing graph to file using graphviz...")
		graphviz_draw(g, vsize = 0.01, penwidth= 0.1, output = d_path)
	
		
	end = time.time()
	print("time elapsed (drawing graph): " + str(end - start))
	print("fertig")
	

def draw_colored_from_raw_file(f_path, p_path, n_part, d_path = None, g_path = None, progress = True):
	start = time.time()

	g = get_graph_from_file(f_path, progress)
	print("graph loaded, calculating nodes positions...")
	pos = calculate_pos(g)

	if(g_path!=None):
		print("Saving graph to file(vertex positions included ! )...")
		g_path = g_path+".xml.gz"
		g.vertex_properties["pos"] = pos
		g.save(g_path)

	print("positions ready, preparing colors...")
	v_color = g.new_vertex_property("float")
	n_nodes = g.num_vertices()
	
	p_list = get_v_part(p_path)
	for i in range(n_nodes):
		v_color[g.vertex(i)] = p_list[i]/n_part;
	
	if d_path!=None:
		graphviz_draw(g, pos=pos, vcolor=v_color, vcmap=matplotlib.cm.Paired, output=d_path)
	else:
		graphviz_draw(g, pos=pos, vcolor=v_color, vcmap=matplotlib.cm.Paired)

	end = time.time()
	print("time elapsed (drawing graph): " + str(end - start))
	print("fertig")
	


def draw_colored_from_file(g_path, p_path = None, n_part = None, d_path = None):
	start = time.time()
	g_path = g_path+".xml.gz"
	g = load_graph(g_path)
	if (str(g.vertex_properties) == "{}"): 
		print("file does not contain positions !")
		return -1.
	
	print("graph loaded")
	pos = g.vertex_properties["pos"]
	print("positions loaded,preparing colors...")
	
	v_color = g.new_vertex_property("float")
	n_nodes = g.num_vertices()

	p_list = get_v_part(p_path)
	for i in range(n_nodes):
		v_color[g.vertex(i)] = p_list[i]/n_part;
	
	print("drawing...")
	if d_path!=None:
		graphviz_draw(g, pos=pos, vcolor=v_color, vcmap=matplotlib.cm.Paired, output=d_path)
	else:
		graphviz_draw(g, pos=pos, vcolor=v_color, vcmap=matplotlib.cm.Paired)
		
	end = time.time()
	print("time elapsed (drawing graph): " + str(end - start))
	print("fertig")
	

def raw_to_svg(f_path, d_path = None, progress = True):
	start = time.time()
	g = get_graph_from_file(f_path, progress)
	print("graph loaded")	
	
	N = g.num_vertices()

	if(N < 20):
		v_size = 0.1
	elif(N > 200000):
		v_size = 0.01
	else:
		x = -0.09/199980.
		b = 0.100009001
		v_size = N*x+b
	
	pen_size = 10*v_size
		
	
	if (d_path ==None):
		print("drawing graph on screen using graphviz...")
		graphviz_draw(g, vsize = v_size, penwidth= pen_size)
	else:
		print("drawing graph to file using graphviz...")
		graphviz_draw(g, vsize = v_size, penwidth= pen_size, output = d_path)
	
		
	end = time.time()
	print("time elapsed (drawing graph): " + str(end - start))
	print("fertig")














