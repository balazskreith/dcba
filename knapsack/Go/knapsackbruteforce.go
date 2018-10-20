package main

import "fmt"

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
	weightLimit int
	items       []Item
	solutions   []int
}

func (solver BruteForceKnapSackSolver) GetWeightLimit() int {
	return solver.weightLimit
}

func (solver BruteForceKnapSackSolver) GetSolutions() []int {
	return solver.solutions
}

func (solver BruteForceKnapSackSolver) selectMax(actualWeight int,
	actualValue int, actualIndex int, actualTrace []int) pair {
	cantFitInKnapSack := solver.GetWeightLimit() <= actualWeight
	checkedAllItems := len(solver.items) <= actualIndex

	if cantFitInKnapSack || checkedAllItems {
		result := pair{first: actualValue, second: actualTrace}
		return result
	}

	item := solver.items[actualIndex]
	currentTrace := append([]int(nil), actualTrace...)
	currentWeight := actualWeight + item.GetWeight()
	currentValue := actualValue + item.GetValue()
	notIncluding := solver.selectMax(actualWeight, actualValue,
		actualIndex+1, currentTrace)
	including := pair{first: 0, second: currentTrace}
	fmt.Println(including)
	if currentWeight <= solver.GetWeightLimit() {
		currentTrace[actualIndex] = 1
		including = solver.selectMax(currentWeight, currentValue,
			actualIndex+1, currentTrace)

		if including.first < notIncluding.first {
			return notIncluding
		}
		return including
	}
	return including
}

func (solver BruteForceKnapSackSolver) solve() pair {
	result := solver.selectMax(0, 0, 0, solver.solutions)
	return result
}
