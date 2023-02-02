package main

import "reflect"

func bubbleSort(numbers []int) {
	n := len(numbers)
	for i := 0; i < n-1; i++ {
		for j := 0; j < n-i-1; j++ {
			if numbers[j] > numbers[j+1] {
				numbers[j], numbers[j+1] = numbers[j+1], numbers[j]
			}
		}
	}
}

func main() {
	numbers := []int{5, 3, 2, 6, 7, 1, 4, 9, 8}
	expectedOutput := []int{1, 2, 3, 4, 5, 6, 7, 8, 9}
	bubbleSort(numbers)
	
	if !reflect.DeepEqual(numbers, expectedOutput) {
		panic("test failed")
	}
}