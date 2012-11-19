a:*.cpp
	g++ $< -g -o a
test:*.cpp
	g++ $< -pg -o test
clean:
	rm a test *.out -f
