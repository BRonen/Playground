package main

import "reflect"

func selectionSort(numbers []int) {
	n := len(numbers)
	for i := 0; i < n-1; i++ {
		minIndex := i
		for j := i + 1; j < n; j++ {
			if numbers[j] < numbers[minIndex] {
				minIndex = j
			}
		}
		numbers[i], numbers[minIndex] = numbers[minIndex], numbers[i]
	}
}

func main() {
	numbers := []int{2, 3, 1, 5, 4, 6, 8, 7, 9}
	expectedOutput := []int{1, 2, 3, 4, 5, 6, 7, 8, 9}
	selectionSort(numbers)
	
	if !reflect.DeepEqual(numbers, expectedOutput) {
		panic("test failed")
	}
}