#pragma once
#include<iostream>
#include<iomanip>
#include"List .h"

using namespace std;

class Warrior;

class Skill
{
protected:
	int points;

public:
	virtual void execute(Warrior* me, Warrior* enemy) = 0;

	Skill(int points) : points(points) {}
	virtual void reset() {}

};


class FireBall : public Skill
{
	virtual void execute(Warrior* me, Warrior* enemy) override;

public:
	FireBall(int points) : Skill(points) {}
};


class BonusHp : public Skill
{
	int count;
	virtual void execute(Warrior* me, Warrior* enemy) override;

public:
	BonusHp(int points) : Skill(points), count(0) {}
	void reset() override
	{
		count = 0;
	}
};


class Freeze : public Skill
{
	bool used;
	virtual void execute(Warrior* me, Warrior* enemy) override;

public:
	Freeze(int points) : Skill(points), used(false) {}
	void reset() override
	{
		used = false;
	}
};



class Warrior
{
	int hp;
	int damage;
	string name;

protected:
	/*List<*/Skill*/*>*/ skill;

public:
	Warrior(int hp, int damage, string name, Skill* skill = nullptr) : hp(hp), damage(damage), name(name), skill(skill) {}
	virtual ~Warrior() {}
	int getHp() { return hp; }
	int getDamage() { return damage; }
	string getName() { return name; }
	void setHp(int h) { hp = h; }
	void setDamage(int d) { damage = d; }

	virtual void attack(Warrior* w) = 0;

	friend ostream& operator<<(ostream& out, const Warrior* w);
	virtual ostream& print(ostream& out) const
	{
		out << " HP: " << hp << ", Damage: " << damage << endl;
		return out;
	}
	void resetSkill()
	{
		if (skill)
		{
			skill->reset();
		}
	}
};

ostream& operator<<(ostream& out, const Warrior* w)
{
	out << setw(12) << left << setfill('.');
	return w->print(out);
}

void FireBall::execute(Warrior* me, Warrior* enemy)
{
	enemy->setHp(enemy->getHp() - points);
	if (enemy->getHp() < 0)
	{
		enemy->setHp(0);
	}
	cout << me->getName() << " Skill (FireBall) -> " << enemy->getName() << endl;
}

void BonusHp::execute(Warrior* me, Warrior* enemy)
{
	if (count == 2)
	{
		return;
	}
	else
	{
		me->setHp(me->getHp() + points);
		cout << me->getName() << " Skill (BonusHp) -> " << me->getName() << endl;
		count++;
	}
}

void Freeze::execute(Warrior* me, Warrior* enemy)
{
	if (used or enemy->getHp() <= 0)
	{
		return;
	}
	used = true;
	cout << me->getName() << " Skill (Freeze) -> "<< enemy->getName() << endl;
	enemy->setHp(enemy->getHp() - points);
	if (enemy->getHp() <= 0)
	{
		enemy->setHp(0);
		return;
	}
	me->attack(enemy);
}




class Light : public Warrior
{
public:
	Light(int hp, int damage, string name, Skill* skill) : Warrior(hp, damage, name, skill) {}
};


class Dark : public Warrior
{
public:
	Dark(int hp, int damage, string name, Skill* skill) : Warrior(hp, damage, name, skill) {}
};








class Archer : public Light
{
public:
	Archer(int hp, int damage, string name, Skill* skill = nullptr) : Light(hp, damage, name, skill) {}
	
	virtual void attack(Warrior* w) override
	{
		if (skill)
		{
			skill->execute(this, w);
		}
		if (w->getHp() <= 0)
		{
			return;
		}
		cout << "Archer fight" << endl;
		w->setHp(w->getHp() - getDamage());
		if (w->getHp() < 0)
		{
			w->setHp(0);
		}
	}

	virtual ostream& print(ostream& out) const override
	{
		out << setw(10) << left << "Archer";
		return Warrior::print(out);
	}
};


class Rider : public Light
{
public:
	Rider(int hp, int damage, string name, Skill* skill = nullptr) : Light(hp, damage, name, skill) {}

	virtual void attack(Warrior* w) override
	{
		if (skill)
		{
			skill->execute(this, w);
		}
		if (w->getHp() <= 0)
		{
			return;
		}
		cout << "Rider fight" << endl;
		w->setHp(w->getHp() - getDamage());
		if (w->getHp() < 0)
		{
			w->setHp(0);
		}
	}

	virtual ostream& print(ostream& out) const override
	{
		out << setw(10) << left << "Rider";
		return Warrior::print(out);
	}
};


class Swordsman : public Light
{
public:
	Swordsman(int hp, int damage, string name, Skill* skill = nullptr) : Light(hp, damage, name, skill) {}

	virtual void attack(Warrior* w) override
	{
		if (skill)
		{
			skill->execute(this, w);
		}
		if (w->getHp() <= 0)
		{
			return;
		}
		cout << "Swordsman fight" << endl;
		w->setHp(w->getHp() - getDamage());
		if (w->getHp() < 0)
		{
			w->setHp(0);
		}
	}

	virtual ostream& print(ostream& out) const override
	{
		out << setw(10) << left << "Swordsman";
		return Warrior::print(out);
	}
};




class Orc : public Dark
{
public:
	Orc(int hp, int damage, string name, Skill* skill = nullptr) : Dark(hp, damage, name, skill) {}

	virtual void attack(Warrior* w) override
	{
		if (skill)
		{
			skill->execute(this, w);
		}
		if (w->getHp() <= 0)
		{
			return;
		}
		cout << "Orc fight" << endl;
		w->setHp(w->getHp() - getDamage());
		if (w->getHp() < 0)
		{
			w->setHp(0);
		}
	}

	virtual ostream& print(ostream& out) const override
	{
		out << setw(10) << left << "Orc";
		return Warrior::print(out);
	}
};


class Zombie : public Dark
{
public:
	Zombie(int hp, int damage, string name, Skill* skill = nullptr) : Dark(hp, damage, name, skill) {}

	virtual void attack(Warrior* w) override
	{
		if (skill)
		{
			skill->execute(this, w);
		}
		if (w->getHp() <= 0)
		{
			return;
		}
		cout << "Zombie fight" << endl;
		w->setHp(w->getHp() - getDamage());
		if (w->getHp() < 0)
		{
			w->setHp(0);
		}
	}

	virtual ostream& print(ostream& out) const override
	{
		out << setw(10) << left << "Zombie";
		return Warrior::print(out);
	}
};


class Skeleton : public Dark
{
public:
	Skeleton(int hp, int damage, string name, Skill* skill = nullptr) : Dark(hp, damage, name, skill) {}

	virtual void attack(Warrior* w) override
	{
		if (skill)
		{
			skill->execute(this, w);
		}
		if (w->getHp() <= 0)
		{
			return;
		}
		cout << "Skeleton fight" << endl;
		w->setHp(w->getHp() - getDamage());
		if (w->getHp() < 0)
		{
			w->setHp(0);
		}
	}

	virtual ostream& print(ostream& out) const override
	{
		out << setw(10) << left << "Skeleton";
		return Warrior::print(out);
	}
};








class WarOfWorld
{
	List<Light*> lights;
	List<Dark*> darks;

public:
	WarOfWorld(int size)
	{
		Light* l = nullptr;
		for (size_t i = 0; i < size; i++)
		{
			int rnd = rand() % 3;
			Skill* skill = nullptr;
			switch (rnd)
			{
			case 0: skill = new FireBall(rand() % 6); break;
			case 1: skill = new BonusHp(rand() % 6 + 15); break;
			case 2: skill = new Freeze(25); break;
			}
			rnd = rand() % 3;
			switch (rnd)
			{
			case 0: l = new Archer(rand() % 20 + 50, rand() % 10 + 10, "Archer", skill); break;
			case 1: l = new Rider(rand() % 30 + 50, rand() % 10 + 10, "Rider", skill); break;
			case 2: l = new Swordsman(rand() % 20 + 50, rand() % 10 + 10, "Swordsman", skill); break;
			}
			lights.push_back(l);
		}

		Dark* d = nullptr;
		for (size_t i = 0; i < size; i++)
		{
			int rnd = rand() % 3;
			Skill* skill = nullptr;
			switch (rnd)
			{
			case 0: skill = new FireBall(rand() % 6 + 10); break;
			case 1: skill = new BonusHp(rand() % 6 + 10); break;
			case 2: skill = new Freeze(15); break;
			}
			rnd = rand() % 3;
			switch (rnd)
			{
			case 0: d = new Orc(rand() % 20 + 50, rand() % 10 + 10, "Orc", skill); break;
			case 1: d = new Zombie(rand() % 30 + 50, rand() % 10 + 10, "Zombie", skill); break;
			case 2: d = new Skeleton(rand() % 20 + 50, rand() % 10 + 10, "Skeleton", skill); break;
			}
			darks.push_back(d);
		}
	}

	void print()
	{ 
		cout << "      ----- LIGHT -----" << "              " << "          ----- DARK -----" << endl;
		lights.print();
		cout << endl;                      
		darks.print(40, 1);
	}

	void game()
	{
		while (lights.getSize() > 0 and darks.getSize() > 0)
		{
			system("cls");
			print();
			int l_ind = rand() % lights.getSize();
			int d_ind = rand() % darks.getSize();
			cout << "---------------------------------------------------------------------" << endl;
			cout << lights[l_ind] << endl;
			cout << darks[d_ind];
			cout << "---------------------------------------------------------------------" << endl;
			cout << endl;
			Warrior* lose = fight(lights[l_ind], darks[d_ind]);
			if (lose == lights[l_ind])
			{
				lights.remove(l_ind);
			}
			else if (lose == darks[d_ind])
			{
				darks.remove(d_ind);
			}
			system("pause");
		}
		system("cls");
		print();
		cout << "War is over!" << endl;
		system("pause");
	}

	Warrior* fight(Warrior* w1, Warrior* w2)
	{
		w1->resetSkill();
		w2->resetSkill();
		Warrior* f = w1;
		Warrior* s = w2;
		if (rand() % 2 == 1)
		{
			f = w2;
			s = w1;
		}
		while (f->getHp() > 0 and s->getHp() > 0)
		{
			f->attack(s);

			if (s->getHp() <= 0)
			{
				cout << f->getName() << " dealt the final hit!" << endl;
				return s;
			}
			s->attack(f);
			if (f->getHp() <= 0)
			{
				cout << s->getName() << " dealt the final hit!" << endl;
				return f;
			}
		}
		if (f->getHp() <= 0)
		{
			return f;
		}
		return s;
	}
};