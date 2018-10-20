package main

import "fmt"

func main() {
	itempool := []Item{
		Item{30, 100}, Item{20, 150},
		Item{10, 200}, Item{15, 500},
		Item{5, 300},
	}

	solver := BruteForceKnapSackSolver{
		weightLimit: 30,
		items:       itempool,
		solutions:   []int{0, 0, 0, 0, 0},
	}

	fmt.Println(solver.solve())

}
