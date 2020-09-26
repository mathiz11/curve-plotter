CXX=g++
CXXFLAGS=-Wall -g
RM=rm -f

main : main.o Operator.o Unknown.o Value.o UnaryOperator.o BinaryOperator.o AbsoluteValue.o Cosine.o Sine.o Tangent.o Addition.o Division.o Multiplication.o Power.o Substraction.o  ez-draw++.o
	$(CXX) -o main main.o Operator.o Unknown.o Value.o UnaryOperator.o BinaryOperator.o AbsoluteValue.o Cosine.o Sine.o Tangent.o Addition.o Division.o Multiplication.o Power.o Substraction.o ez-draw++.o -L/usr/X11R6/lib -lX11 -lXext

main.o : main.cpp Operator.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Operator.o : Operator.cpp Operator.hpp
	$(CXX) $(CXXFLAGS) -c Operator.cpp

Unknown.o : Unknown.cpp Unknown.hpp
	$(CXX) $(CXXFLAGS) -c Unknown.cpp

Value.o : Value.cpp Value.hpp
	$(CXX) $(CXXFLAGS) -c Value.cpp

UnaryOperator.o : UnaryOperator.cpp UnaryOperator.hpp
	$(CXX) $(CXXFLAGS) -c UnaryOperator.cpp

BinaryOperator.o : BinaryOperator.cpp BinaryOperator.hpp
	$(CXX) $(CXXFLAGS) -c BinaryOperator.cpp

AbsoluteValue.o : AbsoluteValue.cpp AbsoluteValue.hpp
	$(CXX) $(CXXFLAGS) -c AbsoluteValue.cpp

Cosine.o : Cosine.cpp Cosine.hpp
	$(CXX) $(CXXFLAGS) -c Cosine.cpp

Sine.o : Sine.cpp Sine.hpp
	$(CXX) $(CXXFLAGS) -c Sine.cpp

Tangent.o : Tangent.cpp Tangent.hpp
	$(CXX) $(CXXFLAGS) -c Tangent.cpp

Addition.o : Addition.cpp Addition.hpp
	$(CXX) $(CXXFLAGS) -c Addition.cpp

Division.o : Division.cpp Division.hpp
	$(CXX) $(CXXFLAGS) -c Division.cpp

Multiplication.o : Multiplication.cpp Multiplication.hpp
	$(CXX) $(CXXFLAGS) -c Multiplication.cpp

Power.o : Power.cpp Power.hpp
	$(CXX) $(CXXFLAGS) -c Power.cpp

Substraction.o : Substraction.cpp Substraction.hpp
	$(CXX) $(CXXFLAGS) -c Substraction.cpp

ez-draw++.o : ez-draw++.cpp ez-draw++.hpp
	$(CXX) $(CXXFLAGS) -c ez-draw++.cpp


clean :
	$(RM) main *.o
