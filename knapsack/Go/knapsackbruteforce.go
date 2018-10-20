package main

type pair struct {
	first  int
	second []int
}

type Item struct {
	weight, value int
}

func (i Item) GetWeight() int {
	return i.weight
}

func (i Item) GetValue() int {
	return i.value
}

type BruteForceKnapSackSolver struct {
	weight_limit int
	items        []Item
	solutions    []int
}

func (solver BruteForceKnapSackSolver) GetWeightLimit() int {
	return solver.weight_limit
}

func (solver BruteForceKnapSackSolver) GetSolutions() []int {
	return solver.solutions
}

func (solver BruteForceKnapSackSolver) selectMax(actual_weight int,
	actual_value int, actual_index int, actual_trace []int) pair {
	cantFitInKnapSack := solver.GetWeightLimit() <= actual_weight
	checkedAllItems := len(solver.items) <= actual_index

	if cantFitInKnapSack || checkedAllItems {
		result := pair{first: actual_value, second: actual_trace}
		return result
	}

	item := solver.items[actual_index]
	current_trace := append([]int(nil), actual_trace...)
	current_weight := actual_weight + item.GetWeight()
	current_value := actual_value + item.GetValue()
	not_including := solver.selectMax(actual_weight, actual_value,
		actual_index+1, current_trace)
	including := pair{first: 0, second: current_trace}

	if current_weight <= solver.GetWeightLimit() {
		current_trace[actual_index] = 1
		including = solver.selectMax(current_weight, current_value,
			actual_index+1, current_trace)

		if including.first < not_including.first {
			return not_including
		} else {
			return including
		}
	}
	return including
}

func (solver BruteForceKnapSackSolver) solve() pair {
	result := solver.selectMax(0, 0, 0, solver.solutions)
	return result
}
