CC := gcc
CFLAGS := -Wall -Werror -std=c11 -I./include
SRCDIR := ./src
EXAMPLESDIR := ./examples
OBJDIR := ./obj
BINDIR := ./bin

.PHONY: all mkbin clean

all: mkbin e_array_list e_d_linked_list e_graph e_linked_list e_queue e_stack e_hash_map

mkbin:
	mkdir -p $(BINDIR) $(OBJDIR)

e_array_list: $(EXAMPLESDIR)/e_array_list.c $(OBJDIR)/array_list.o
	$(CC) $(CFLAGS) -o $(BINDIR)/$@ $^

e_d_linked_list: $(EXAMPLESDIR)/e_d_linked_list.c $(OBJDIR)/d_linked_list.o
	$(CC) $(CFLAGS) -o $(BINDIR)/$@ $^

e_graph: $(EXAMPLESDIR)/e_graph.c $(OBJDIR)/graph_adj_mat.o
	$(CC) $(CFLAGS) -o $(BINDIR)/$@ $^

e_linked_list: $(EXAMPLESDIR)/e_linked_list.c $(OBJDIR)/linked_list.o
	$(CC) $(CFLAGS) -o $(BINDIR)/$@ $^

e_queue: $(EXAMPLESDIR)/e_queue.c $(OBJDIR)/queue.o $(OBJDIR)/d_linked_list.o
	$(CC) $(CFLAGS) -o $(BINDIR)/$@ $^

e_stack: $(EXAMPLESDIR)/e_stack.c $(OBJDIR)/stack.o $(OBJDIR)/linked_list.o
	$(CC) $(CFLAGS) -o $(BINDIR)/$@ $^

e_hash_map: $(EXAMPLESDIR)/e_hash_map.c $(OBJDIR)/hash_map.o
	$(CC) $(CFLAGS) -o $(BINDIR)/$@ $^

$(OBJDIR)/array_list.o: $(SRCDIR)/array_list.c
	$(CC) $(CFLAGS) -c -o $@ $^

$(OBJDIR)/d_linked_list.o: $(SRCDIR)/d_linked_list.c
	$(CC) $(CFLAGS) -c -o $@ $^

$(OBJDIR)/graph_adj_mat.o: $(SRCDIR)/graph_adj_mat.c
	$(CC) $(CFLAGS) -c -o $@ $^

$(OBJDIR)/linked_list.o: $(SRCDIR)/linked_list.c
	$(CC) $(CFLAGS) -c -o $@ $^

$(OBJDIR)/queue.o: $(SRCDIR)/queue.c
	$(CC) $(CFLAGS) -c -o $@ $^

$(OBJDIR)/stack.o: $(SRCDIR)/stack.c
	$(CC) $(CFLAGS) -c -o $@ $^

$(OBJDIR)/hash_map.o: $(SRCDIR)/hash_map.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(BINDIR) $(OBJDIR)


