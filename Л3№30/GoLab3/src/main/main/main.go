package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {

	var data uint16

	fmt.Println("Enter C: [0-31] ")
	var C uint16
	fmt.Scanln(&C)

	var ZERO uint16 = 0

	fmt.Println("Enter F: [0-1] ")
	var F uint16
	fmt.Scanln(&F)

	fmt.Println("Enter B: [0-1] ")
	var B uint16
	fmt.Scanln(&B)

	fmt.Println("Enter N: [0-255] ")
	var N uint16
	fmt.Scanln(&N)

	firstApp(&data, C, ZERO, F, B, N)

	hexStr := strconv.FormatInt(int64(data), 16)

	fmt.Printf("0x%s\n", strings.ToUpper(hexStr))

	fmt.Println("Enter a packed structure as a number (0x format): ")
	fmt.Scan(&data)

	secondApp(&C, &ZERO, &F, &B, &N, data)

}
func firstApp(data *uint16, C uint16, ZERO uint16, F uint16, B uint16, N uint16) {
	*data = N
	*data = B<<8 | *data
	*data = F<<9 | *data
	*data = ZERO<<10 | *data
	*data = C<<11 | *data
}

func secondApp(C *uint16, ZERO *uint16, F *uint16, B *uint16, N *uint16, data uint16) {
	*N = data & 0xFF
	*B = (data >> 8) & 0x1
	*F = (data >> 9) & 0x1
	*ZERO = (data >> 10) & 0x1
	*C = (data >> 11) & 0x1F

	fmt.Printf("N = %d\n", *N)
	fmt.Printf("B = %d\n", *B)
	fmt.Printf("F = %d\n", *F)
	fmt.Printf("C = %d\n", *C)
}
