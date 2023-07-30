package main

import (
	"github.com/savsgio/atreugo/v11"
)

type Device struct {
	ID       int    `json:"id"`
	Mac      string `json:"mac"`
	Firmware string `json:"firmware"`
}

func main() {
	config := atreugo.Config{
		Addr: "0.0.0.0:8001",
	}
	r := atreugo.New(config)
	r.GET("/api/devices", getDevices)
	r.POST("/api/devices", createDevice)
}

func getDevices(c *atreugo.RequestCtx) {
	dvs := []Device{
		{1, "5F-33-CC-1F-43-82", "2.1.6"},
		{2, "EF-2B-C4-F5-D6-34", "2.1.6"},
	}

	c.JSON(http.StatusOK, dvs)
}

func createDevice(c *atreugo.RequestCtx) {
	number := 40

	fib := fibonacci(number)

	c.JSON(http.StatusCreated, atreugo.H{"fib": fib})
}

func fibonacci(n int) int {
	if n <= 1 {
		return n
	}
	return fibonacci(n-1) + fibonacci(n-2)
}
