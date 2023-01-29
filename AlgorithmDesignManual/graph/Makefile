CC=gcc
CFLAGS=-Wall -g

OBJS=graph.o bfs.o dfs.o test_graph twocolor find_cycle edge_classification.o articulation_vertices scc topsort chromatic

ALL: $(OBJS)

chromatic: chromatic.c graph.o
	$(CC) $(CFLAGS) chromatic.c graph.o ../datastructure/queue.o -o chromatic

topsort: topsort.c graph.o dfs.o edge_classification.o
	$(CC) $(CFLAGS) topsort.c graph.o dfs.o edge_classification.o ../datastructure/stack.o -o topsort

scc: scc.c graph.o dfs.o edge_classification.o
	$(CC) $(CFLAGS) scc.c graph.o dfs.o edge_classification.o ../datastructure/stack.o -o scc

articulation_vertices: articulation_vertices.c graph.o dfs.o edge_classification.o
	$(CC) $(CFLAGS) articulation_vertices.c graph.o dfs.o edge_classification.o -o articulation_vertices

find_cycle: find_cycle.c graph.o dfs.o 
	$(CC) $(CFLAGS) find_cycle.c graph.o dfs.o -o find_cycle

test_graph: test_graph.c graph.o  bfs.o
	$(CC) $(CFLAGS) test_graph.c graph.o bfs.o ../datastructure/queue.o -o test_graph

graph.o: graph.c
	$(CC) $(CFLAGS) -c graph.c -o graph.o

bfs.o: bfs.c
	$(CC) $(CFLAGS) -c bfs.c -o bfs.o

dfs.o: dfs.c 
	$(CC) $(CFLAGS) -c dfs.c -o dfs.o

twocolor: twocolor.c graph.o bfs.o
	$(CC) $(CFLAGS) twocolor.c graph.o bfs.o ../datastructure/queue.o -o twocolor

edge_classification.o: edge_classification.c
	$(CC) $(CFLAGS) -c edge_classification.c -o edge_classification.o

clean:
	rm -f $(OBJS)
	rm -rf *.dSYM

test:
	cat test.txt | ./test_graph

test_twocolor:
	cat bipartite.txt | ./twocolor

test_findcycle: 
	cat test.txt | ./find_cycle

test_scc: 
	cat scc_test.txt | ./scc

test_articulation:
	cat articulation_test.txt | ./articulation_vertices

test_topsort:
	cat topsort_test.txt | ./topsort