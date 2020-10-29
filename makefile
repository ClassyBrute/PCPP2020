OBJS = main.o Game.o Player.o Enemy.o Weapon.o Map.o
CXX = g++
CXXFLAGS = -Wall -std=c++17
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

game: $(OBJS)
	$(CXX) $(CXXFLAGS) -o game $(OBJS) $(LDLIBS)

$(OBJS): Game.h

$(OBJS): Player.h

$(OBJS): Enemy.h

$(OBJS): Weapon.h

$(OBJS): Map.h

clean:
	$(RM) game $(OBJS)
