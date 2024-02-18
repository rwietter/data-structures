// generics2
// Make me compile!

package main

import "fmt"

type Number interface {
	float64
}

func main() {
	fmt.Println(addNumbers(1, 2))
	fmt.Println(addNumbers(1.0, 2.3))
}

func addNumbers[T Number](n1 T, n2 T) float32 {
	return float32(n1 + n2)
}
