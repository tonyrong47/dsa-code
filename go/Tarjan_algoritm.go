package main

import "fmt"

var time int

func tarjanDFS(u int, graph [][]int, disc, low []int, stack *[]int, inStack []bool, sccs *[][]int) {
	time++
	disc[u] = time
	low[u] = time
	*stack = append(*stack, u)
	inStack[u] = true

	// Explore neighbors
	for _, v := range graph[u] {
		if disc[v] == -1 {
			tarjanDFS(v, graph, disc, low, stack, inStack, sccs)
			low[u] = min(low[u], low[v])
		} else if inStack[v] {
			low[u] = min(low[u], disc[v])
		}
	}

	// If u is head of SCC
	if disc[u] == low[u] {
		var scc []int
		for {
			n := (*stack)[len(*stack)-1]
			*stack = (*stack)[:len(*stack)-1]
			inStack[n] = false
			scc = append(scc, n)
			if n == u {
				break
			}
		}
		*sccs = append(*sccs, scc)
	}
}

func tarjan(graph [][]int, n int) [][]int {
	disc := make([]int, n)
	low := make([]int, n)
	inStack := make([]bool, n)
	for i := 0; i < n; i++ {
		disc[i] = -1
		low[i] = -1
	}

	var stack []int
	var sccs [][]int
	time = 0

	for i := 0; i < n; i++ {
		if disc[i] == -1 {
			tarjanDFS(i, graph, disc, low, &stack, inStack, &sccs)
		}
	}

	return sccs
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	// Example graph
	// 0 → 1, 1 → 2, 2 → 0, 1 → 3, 3 → 4
	graph := [][]int{
		{1},
		{2, 3},
		{0},
		{4},
		{},
	}

	n := len(graph)
	sccs := tarjan(graph, n)

	fmt.Println("Strongly Connected Components (SCCs):")
	for _, scc := range sccs {
		fmt.Println(scc)
	}
}
