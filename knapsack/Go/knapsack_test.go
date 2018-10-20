package main

import (
	"reflect"
	"testing"
)

func TestItemWeight(t *testing.T) {
	item := Item{weight: 1, value: 2}
	if item.GetWeight() != 1 {
		t.Error("Expected 1, got ", item.weight)
	}
}

func TestItemValue(t *testing.T) {
	item := Item{weight: 1, value: 2}
	if item.GetValue() != 2 {
		t.Error("Expected 2, got ", item.value)
	}
}

func TestBruteForceSolverWeightLimit(t *testing.T) {
	solver := BruteForceKnapSackSolver{weightLimit: 1,
		items: []Item{
			Item{1, 2}, Item{1, 2},
		},
		solutions: []int{1, 0, 0, 1},
	}
	if solver.weightLimit != 1 {
		t.Error("Expected 1, got ", solver.weightLimit)
	}
}

func TestBruteForceSolverSolutions(t *testing.T) {
	solver := BruteForceKnapSackSolver{weightLimit: 30,
		items: []Item{
			Item{30, 100}, Item{20, 150},
			Item{10, 200}, Item{15, 500},
			Item{5, 300},
		},
		solutions: []int{0, 0, 0, 0, 0},
	}
	expectedSolution := pair{first: 1000, second: []int{0, 0, 1, 1, 1}}
	if !reflect.DeepEqual(solver.solve(), expectedSolution) {
		t.Error("Expected {1000,  [0, 0, 1, 1, 1]}. got ", solver.solve())
	}
}
