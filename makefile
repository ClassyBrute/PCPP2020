OBJS = main.o Game.o Player.o Enemy.o Weapon.o Map.o Menu.o MenuHelp.o MenuShop.o Bullet.o Coin.o Heart.o
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

$(OBJS): Menu.h

$(OBJS): MenuHelp.h

$(OBJS): MenuShop.h

$(OBJS): Bullet.h

$(OBJS): Coin.h

$(OBJS): Heart.h

clean:
	$(RM) game $(OBJS)

