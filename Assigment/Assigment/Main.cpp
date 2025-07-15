#include <iostream>
#include "Tile.h"
#include "Joker.h"
#include "Pool.h"
#include "Rack.h"
#include "Set.h"
#include "GroupSet.h"
#include "RunSet.h"
#include "Sets.h"

using namespace std;

void tileTest() {
	cout << "Tiles and Jokers Test" << endl;
	cout << "=====================" << endl;
	Tile* t1 = new Tile('R', 13);
	Tile* t2 = new Tile('K', 1);

	cout << "Tile t1: R13" << endl;
	cout << "T1: " << t1->getColor() << endl;
	cout << "T2: " << t1->getNumber() << endl;
	cout << "T3: " << t1->isJoker() << endl;
	cout << "T4: " << t1->getScore() << endl;
	cout << "T6: ";   t1->display();   cout << endl;
	cout << endl;

	cout << "Tile t2: K1" << endl;
	cout << "T1: " << t2->getColor() << endl;
	cout << "T2: " << t2->getNumber() << endl;
	cout << "T3: " << t2->isJoker() << endl;
	cout << "T4: " << t2->getScore() << endl;
	cout << "T6: ";	  t2->display();   cout << endl;
	cout << endl;

	Tile* j1 = new Joker();	// from pool / rack
	cout << "Tile j1: Joker" << endl;
	cout << "T1: " << j1->getColor() << endl;
	cout << "T2: " << j1->getNumber() << endl;
	cout << "T3: " << j1->isJoker() << endl;
	cout << "T4: " << j1->getScore() << endl;
	cout << "T6: ";   j1->display();   cout << endl;
	cout << endl;

	cout << "Setting color and number of joker to R6" << endl;
	((Joker*)j1)->setColor('R');
	((Joker*)j1)->setNumber(6);
	cout << "T5: " << j1->getColor() << endl;
	cout << "T5: " << j1->getNumber() << endl;
	cout << "T3: " << j1->isJoker() << endl;
	cout << "T4: " << j1->getScore() << endl;
	cout << "T6: ";   j1->display();   cout << endl;
	cout << endl;
}

void poolTest() {
	cout << "Pool Test" << endl;
	cout << "=========" << endl;

	Pool* p = new Pool();
	cout << "P1 and P5 Test:" << endl;
	p->display();
	cout << endl << endl;

	cout << "P3 Test: ";
	Tile* t = p->draw();
	t->display();
	cout << endl;
	p->display();
	cout << endl << endl;

	cout << "P4 Test:" << endl;
	p->put(t);
	p->display();
	cout << endl << endl;

	cout << "P2 Test:" << endl;
	p->shuffle();
	p->display();
	cout << endl << endl;
}

void rackTest() {
	cout << "Rack Test (make use of Pool)" << endl;
	cout << "============================" << endl;

	Pool* p = new Pool();
		
	cout << "R1 and R5 Test: " << endl;
	Rack* r = new Rack();
	for (int i = 0; i < 14; i++) {
		Tile* t = p->draw();
		r->put(t);
	}
	r->display();
	cout << endl << endl;

	cout << "R2 Test (with Joker added to pos 2): " << endl;
	r->insert(2, new Joker());
	r->display();
	cout << endl << endl;

	cout << "R3 Test (pos 3): " << endl;
	Tile* popped = r->pop(3);
	popped->display();
	cout << endl;
	r->display();
	cout << endl << endl;

	cout << "R4 Test: " << r->getPoints() << endl << endl;

	while (r->size() > 3) {
		r->pop(3);
	}
	cout << "R4 Test: " << r->getPoints() << endl << endl;
}

void setTest() {
	cout << "Set and Sets Test" << endl;
	cout << "=================" << endl;

	Tile* t000 = new Tile('R', 3);
	Tile* t001 = new Tile('Y', 3);
	Tile* t002 = new Tile('B', 3);
	Tile* t003 = new Tile('K', 3);
	Tile* t004 = new Tile('K', 4);
	Tile* t005 = new Tile('K', 5);
	Tile* t006 = new Tile('K', 6);
	Tile* t007 = new Tile('K', 7);
	Tile* t008 = new Tile('K', 8);
	Tile* t009 = new Tile('K', 9);
	Tile* t010 = new Tile('K', 10);
	Tile* t011 = new Tile('K', 11);
	Tile* t012 = new Tile('K', 12);
	Tile* t013 = new Tile('K', 13);
	Tile* t100 = new Joker();
	Tile* t200 = new Joker();

	cout << "-- Group Set -->" << endl;
	Set* gs1 = new GroupSet();
	
	bool b1 = gs1->put(t000);
	cout << "S1, S2 & S8: Adding R3 to an empty group set: " << b1 << endl;
	gs1->display(false);   cout << endl;

	bool b2 = gs1->put(t004);
	cout << "S1, S2 & S8: Adding K4 to an empty group set: " << b2 << endl;
	gs1->display(true);   cout << endl;

	gs1->put(t001);
	gs1->put(t002);
	gs1->put(t003);
	cout << "S3 Test:" << endl;
	gs1->display(true);   cout << endl;
	Tile* popped1 = gs1->pop(2);
	cout << "S3 Test (popped pos 2): ";
	popped1->display();   cout << endl;
	gs1->display(true);   cout << endl;
	
	cout << "S4 to S7 Test (put back, split and merge)" << endl;
	cout << "is complete: " << gs1->isComplete() << endl;
	gs1->put(popped1);
	gs1->display(true);   cout << endl;
	Set* gs1s = gs1->split(2);
	gs1->display(false);	cout << endl;
	gs1s->display(false);	cout << endl;
	cout << endl;
	
	gs1s->merge(gs1);
	gs1->display(false);	cout << endl;
	gs1s->display(false);	cout << endl;
	cout << "size: " << gs1s->size() << endl;
	
	cout << "<-- Group Set --" << endl;

	cout << "-- Run Set -->" << endl;
	Set* rs1 = new RunSet();

	bool b3 = rs1->put(t005);
	cout << "S1, S2 & S8: Adding K5 to an empty group set: " << b3 << endl;
	rs1->display(false);   cout << endl;

	bool b4 = rs1->put(t004);
	cout << "S1, S2 & S8: Adding K4 to an empty group set: " << b4 << endl;
	rs1->display(true);   cout << endl;

	bool b5 = rs1->put(t006);
	cout << "S1, S2 & S8: Adding K6 to an empty group set: " << b5 << endl;
	rs1->display(true);   cout << endl;

	bool b6 = rs1->put(t008);
	cout << "S1, S2 & S8: Adding K8 to an empty group set: " << b6 << endl;
	rs1->display(true);   cout << endl;

	bool b7 = rs1->put(t007);
	cout << "S1, S2 & S8: Adding K7 to an empty group set: " << b7 << endl;
	rs1->display(true);   cout << endl;

	cout << "S3 Test:" << endl;
	rs1->display(true);   cout << endl;
	Tile* popped2 = rs1->pop(2);
	cout << "S3 Test (popped pos 2): ";
	popped2->display();   cout << endl;
	rs1->display(true);   cout << endl;

	
	cout << "S4 to S7 Test (split, put back and merge)" << endl;
	cout << "is not complete: " << rs1->isComplete() << endl;
	Set* rs1s = rs1->split(2);
	rs1->display(false);	cout << endl;
	rs1s->display(false);	cout << endl;
	cout << endl;

	((Joker*)t100)->setColor('K');
	((Joker*)t100)->setNumber(6);
	rs1s->put(t100);
	rs1s->display(true);   cout << endl;

	rs1->merge(rs1s);
	rs1->display(false);	cout << endl;
	rs1s->display(false);	cout << endl;
	cout << "size: " << rs1->size() << endl;

	cout << "<-- Run Set --" << endl;

	cout << "-- Sets Test -->" << endl;

	Sets* sets = new Sets();
	sets->put(gs1s);
	sets->put(gs1);
	sets->put(rs1);

	sets->display();
	cout << "Ss1 Test: clean up" << endl;
	sets->cleanUp();
	sets->display();

	RunSet* rs2 = new RunSet();
	rs2->put(t008);
	rs2->put(t009);
	rs2->put(t010);

	sets->put(rs2);
	cout << "Ss2 Test: (swap 1 & 2 then 1 & 0) " << endl;
	sets->display();
	sets->swap(1, 2);
	sets->display();
	sets->swap(1, 0);
	sets->display();

	cout << "Ss3 Test: (insert a new set to pos 1) " << endl;

	RunSet* rs3 = new RunSet();
	rs3->put(t011);
	rs3->put(t012);
	rs3->put(t013);
	sets->insert(1, rs3);
	sets->display();
	
	cout << "<-- Sets Test --" << endl;
}

int main() {

	tileTest();
	cout << endl << endl;

	poolTest();
	cout << endl << endl;

	rackTest();
	cout << endl << endl;

	setTest();
	cout << endl << endl;

	return 0;
}

/*Sample Output

Tiles and Jokers Test
=====================
Tile t1: R13
T1: R
T2: 13
T3: 0
T4: 13
T6: R13

Tile t2: K1
T1: K
T2: 1
T3: 0
T4: 1
T6: K1

Tile j1: Joker
T1: -
T2: 0
T3: 1
T4: 30
T6: :-)

Setting color and number of joker to R6
T5: R
T5: 6
T3: 1
T4: 0
T6: [R6]



Pool Test
=========
P1 and P5 Test:
R1 R1 R2 R2 R3 R3 R4 R4 R5 R5 R6 R6 R7 R7 R8 R8 R9 R9 R10 R10 R11 R11 R12 R12 R13 R13 B1 B1 B2 B2 B3 B3 B4 B4 B5 B5 B6 B6 B7 B7 B8 B8 B9 B9 B10 B10 B11 B11 B12 B12 B13 B13 Y1 Y1 Y2 Y2 Y3 Y3 Y4 Y4 Y5 Y5 Y6 Y6 Y7 Y7 Y8 Y8 Y9 Y9 Y10 Y10 Y11 Y11 Y12 Y12 Y13 Y13 K1 K1 K2 K2 K3 K3 K4 K4 K5 K5 K6 K6 K7 K7 K8 K8 K9 K9 K10 K10 K11 K11 K12 K12 K13 K13 :-) :-)

P3 Test: B10
R1 R1 R2 R2 R3 R3 R4 R4 R5 R5 R6 R6 R7 R7 R8 R8 R9 R9 R10 R10 R11 R11 R12 R12 R13 R13 B1 B1 B2 B2 B3 B3 B4 B4 B5 B5 B6 B6 B7 B7 B8 B8 B9 B9 B10 B11 B11 B12 B12 B13 B13 Y1 Y1 Y2 Y2 Y3 Y3 Y4 Y4 Y5 Y5 Y6 Y6 Y7 Y7 Y8 Y8 Y9 Y9 Y10 Y10 Y11 Y11 Y12 Y12 Y13 Y13 K1 K1 K2 K2 K3 K3 K4 K4 K5 K5 K6 K6 K7 K7 K8 K8 K9 K9 K10 K10 K11 K11 K12 K12 K13 K13 :-) :-)

P4 Test:
R1 R1 R2 R2 R3 R3 R4 R4 R5 R5 R6 R6 R7 R7 R8 R8 R9 R9 R10 R10 R11 R11 R12 R12 R13 R13 B1 B1 B2 B2 B3 B3 B4 B4 B5 B5 B6 B6 B7 B7 B8 B8 B9 B9 B10 B11 B11 B12 B12 B13 B13 Y1 Y1 Y2 Y2 Y3 Y3 Y4 Y4 Y5 Y5 Y6 Y6 Y7 Y7 Y8 Y8 Y9 Y9 Y10 Y10 Y11 Y11 Y12 Y12 Y13 Y13 K1 K1 K2 K2 K3 K3 K4 K4 K5 K5 K6 K6 K7 K7 K8 K8 K9 K9 K10 K10 K11 K11 K12 K12 K13 K13 :-) :-) B10

P2 Test:
Y8 B2 R9 Y3 B10 Y10 R11 R1 R3 R12 Y11 K4 Y7 R6 K1 K2 B5 K13 R8 B4 R1 Y2 R5 B8 B2 K8 B12 R9 K7 K11 K7 Y12 Y11 B6 R13 K10 K12 K5 B13 Y12 B10 R5 B9 B3 B3 K3 Y6 Y4 :-) B12 B13 Y1 B4 K11 B9 R8 Y13 Y5 K5 K9 R13 K9 B8 Y4 R10 Y7 Y10 K4 B1 :-) K8 K10 Y1 B5 R4 B1 R11 Y3 R7 Y5 K2 Y6 B11 Y9 Y8 R10 R6 B11 B6 B7 Y13 K1 R2 K6 R2 Y2 R12 R4 K13 R7 B7 R3 Y9 K3 K6 K12



Rack Test (make use of Pool)
============================
R1 and R5 Test:
B10 K11 Y12 B9 R9 B3 Y4 Y4 K9 K12 B9 K1 R2 K5
0   1   2   3  4  5  6  7  8  9   10 11 12 13


R2 Test (with Joker added to pos 2):
B10 K11 :-) Y12 B9 R9 B3 Y4 Y4 K9 K12 B9 K1 R2 K5
0   1   2   3   4  5  6  7  8  9  10  11 12 13 14


R3 Test (pos 3):
Y12
B10 K11 :-) B9 R9 B3 Y4 Y4 K9 K12 B9 K1 R2 K5
0   1   2   3  4  5  6  7  8  9   10 11 12 13


R4 Test: 118

R4 Test: 51



Set and Sets Test
=================
-- Group Set -->
S1, S2 & S8: Adding R3 to an empty group set: 1
R3

S1, S2 & S8: Adding K4 to an empty group set: 0
R3
0

S3 Test:
R3 Y3 B3 K3
0  1  2  3

S3 Test (popped pos 2): B3
R3 Y3 K3
0  1  2

S4 to S7 Test (put back, split and merge)
is complete: 1
R3 Y3 K3 B3
0  1  2  3

R3 Y3

K3 B3




K3 B3 R3 Y3

size: 4
<-- Group Set --
-- Run Set -->
S1, S2 & S8: Adding K5 to an empty group set: 1
K5

S1, S2 & S8: Adding K4 to an empty group set: 1
K4 K5
0  1

S1, S2 & S8: Adding K6 to an empty group set: 1
K4 K5 K6
0  1  2

S1, S2 & S8: Adding K8 to an empty group set: 0
K4 K5 K6
0  1  2

S1, S2 & S8: Adding K7 to an empty group set: 1
K4 K5 K6 K7
0  1  2  3

S3 Test:
K4 K5 K6 K7
0  1  2  3

S3 Test (popped pos 2): K6
K4 K5 K7
0  1  2

S4 to S7 Test (split, put back and merge)
is not complete: 0
K4 K5

K7


[K6] K7
0    1

K4 K5 [K6] K7



size: 4
<-- Run Set --
-- Sets Test -->
0:K3 B3 R3 Y3

1:

2:K4 K5 [K6] K7

Ss1 Test: clean up
0:K3 B3 R3 Y3

1:K4 K5 [K6] K7

Ss2 Test: (swap 1 & 2 then 1 & 0) :
0:K3 B3 R3 Y3

1:K4 K5 [K6] K7

2:K8 K9 K10

0:K3 B3 R3 Y3

1:K8 K9 K10

2:K4 K5 [K6] K7

0:K8 K9 K10

1:K3 B3 R3 Y3

2:K4 K5 [K6] K7

Ss3 Test: (insert a new set to pos 1)
0:K8 K9 K10

1:K11 K12 K13

2:K3 B3 R3 Y3

3:K4 K5 [K6] K7

<-- Sets Test --


*/