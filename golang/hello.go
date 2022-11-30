package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println("hello world")
	var a, b, c float64
	fmt.Print("Enter the length of the sides : ")
	fmt.Scan(&a, &b, &c)
	if a < b+c && b < c+a && c < a+b {
		var s = (a + b + c) / 2
		var area = s * (s - a) * (s - b) * (s - c)
		fmt.Printf("The Area of the Triangle is : = %.2f \n", math.Sqrt(area))
	} else {
		fmt.Println("Triangle not possible...")
	}
}
