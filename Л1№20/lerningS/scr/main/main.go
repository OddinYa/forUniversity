package main

import (
	"fmt"
	"math"
)

func main() {
	var b float64

	fmt.Scan(&b)

	fmt.Println(first(b))
	fmt.Println(second(b))

}

func first(b float64) float64 {
	
	var x = math.Sqrt(2*b + 2*(math.Sqrt(math.Pow(b, 2)-4)))
	var c = math.Sqrt(math.Pow(b, 2)-4) + b + 2

	return x / c
}
func second(b float64) float64 {

	return 1 / math.Sqrt((b + 2))
}
