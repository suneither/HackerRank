Design a class named Box whose dimensions are integers and private to the class. The dimensions are labelled: length $l$, breadth $b$, and height $h$.

The default constructor of the class should initialize $l$, $b$, and $h$ to 0.

The parameterized constructor Box(int length, int breadth, int height) should initialize Box's $l,\ b$ and $h$ to length, breadth and height.

The copy constructor Box (Box $B$) should set $l,\ b$ and $h$ to $B$'s $l,\ b$ and $h$, respectively.

Apart from the above, the class should have $4$ functions:

- int getLength() - Return box's length
- int getBreadth() - Return box's breadth
- int getHeight() - Return box's height
- long long CalculateVolume() - Return the volume of the box

Overload the operator $<$ for the class Box. Box $A <$ Box $B$ if:

1. $A.l < B.l$
2. $A.b < B.b$ and $A.l == B.l$
3. $A.h < B.h$ and $A.b == B.b$ and $A.l == B.l$

Overload operator $<<$ for the class Box().

If $B$ is an object of class Box:  

$cout << B$ should print $B.l$, $B.b$ and $B.h$ on a single line separated by spaces.

For example,

```
    Box b1; // Should set b1.l = b1.b = b1.h = 0;
    Box b2(2, 3, 4); // Should set b1.l = 2, b1.b = 3, b1.h = 4;
    b2.getLength();	// Should return 2
    b2.getBreadth(); // Should return 3
    b2.getheight();	// Should return 4
    b2.CalculateVolume(); // Should return 24
    bool x = (b1 < b2);	// Should return true based on the conditions given
    cout<<b2; // Should print 2 3 4 in order.
```

**Constraints**

$0 \le l,b,h \le 10^5$

Two boxes being compared using the $<$ operator will not have all three dimensions equal.

**Input Format**

- First line defines how many boxes will be checked using `check2()` function
- Each subsequent line first integer sets `type` out of 5 possible types which defines what input and how output will be handled.  
(for e.g. type 2) will expect 3 more integers length, breadth, height

**Note**: see `check2()` function to understand each `type`.

**Sample Input**

```
    5
    2 3 4 5
    4
    5
    4
    2 4 6 7
```

**Explanation**

- first line: $5$ is the number of checks this program will execute.
- second line: $2$ is the `type` number and $3,4,5$ are box dimensions.
- third-fifth lines: are the `type` numbers.
- last line: $2,4,6,7$ numbers are same as second line. 

**Sample Output**

```
    3 4 5
    60
    3 4 5
    60
    4 6 7
```

**Explanation**

- first line: prints $3\ 4\ 5$ which are box dimentions: $l, b, h$. It is executed on `type = 2` place
- second line: prints $60$ which is the volume of box dimentions. It is executed on `type = 4` place
- third line: prints $3\ 4\ 5$ which are box dimentions: $l, b, h$. but is executed on `type = 5` place
- forth line: prints $60$ which is the volume of box dimentions. It is executed on `type = 4` place
- fifth line: prints $4\ 6\ 7$ which are box dimentions: $l, b, h$. It is executed on `type = 2` place