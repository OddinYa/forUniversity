package main

import (
	"fmt"
	"math"
)

func main() {

	var x float32
	var y float32

	fmt.Println("Enter X :")
	fmt.Scanln(&x)
	fmt.Println("Enter Y :")
	fmt.Scanln(&y)

	var resutl bool = checking(x, y)

	if resutl {
		fmt.Println("It's Ok")
	} else {
		fmt.Println("It's not")
	}
}

func checking(x, y float32) bool {

	var first bool = math.Pow(float64(x), 2)+math.Pow(float64(y), 2) <= math.Pow(1, 2)

	var second bool = (x >= -1 && x <= 0) && (y <= 1 && y >= 0)

	return first || second
}
