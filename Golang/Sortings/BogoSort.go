package main

import (
	"math/rand"
	"time"
	"reflect"
	"fmt"
)

func isSorted(arr []int) bool {
	n := len(arr)
	for i := 0; i < n-1; i++ {
		if arr[i] > arr[i+1] {
			return false
		}
	}
	return true
}

func shuffle(arr []int) {
	rand.Seed(time.Now().UnixNano())
	n := len(arr)
	for i := n - 1; i > 0; i-- {
		j := rand.Intn(i)
		arr[i], arr[j] = arr[j], arr[i]
	}
}

func bogoSort(arr []int) {
	for !isSorted(arr) {
		fmt.Println(arr)
		shuffle(arr)
	}
}

func main() {
	numbers := []int{3, 5, 7, 9, 1, 4, 2, 6, 8}
	expectedOutput := []int{1, 2, 3, 4, 5, 6, 7, 8, 9}

	bogoSort(numbers)

	if(!reflect.DeepEqual(numbers, expectedOutput)) {
		panic("test failed")
	}
}