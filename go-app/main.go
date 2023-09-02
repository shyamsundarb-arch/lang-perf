package main

import (
	"net/http"

	"github.com/savsgio/atreugo/v11"

	"math/rand"
)

type Device struct {
	ID       int    `json:"id"`
	Mac      string `json:"mac"`
	Firmware string `json:"firmware"`
}

func main() {
	config := atreugo.Config{
		Addr:    "0.0.0.0:8001",
		Prefork: true,
	}
	r := atreugo.New(config)
	r.GET("/api/devices", getDevices)
	r.POST("/api/devices", createDevice)
	if err := r.ListenAndServe(); err != nil {
		panic(err)
	}
}

func getDevices(c *atreugo.RequestCtx) error {
	dvs := []Device{
		{1, "5F-33-CC-1F-43-82", "2.1.6"},
		{2, "EF-2B-C4-F5-D6-34", "2.1.6"},
	}

	return c.JSONResponse(dvs, http.StatusOK)
}

func createDevice(c *atreugo.RequestCtx) error {
	number := rand.Intn(40-5+1) + 5

	fib := fibonacci(number)

	return c.JSONResponse(atreugo.JSON{"fib": fib}, http.StatusCreated)
}
func fibonacci(n int) int {
	switch n {
	case 1, 2:
		return 1
	case 3:
		return 2
	default:
		return fibonacci(n-1) + fibonacci(n-2)
	}
}
