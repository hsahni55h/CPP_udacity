// Susbscript Notation

    array_name[index]
    pointer_name[index]


// Offset notation

    *(array_name + index)
    *(pointer_name + index)

-----------------------------------------------------------------------------------------------------
CASE1:

const int *pointer(&variable) - data pointed by the pointer is constant and cannot be changed

example:

int high_score{100};
int low_score{65};

cont int *score_ptr{&high_score};

*score_ptr = 86;    // ERROR
score_ptr = &low_score;    //OK

------------------------------------------------------------------------------------------------------
CASE2:

const *int pointer(&variable) - data pointed to by the pointer can be changed but the pointer itself cannot point somewhere else.

example:

int high_score{100};
int low_score{65};

cont *int score_ptr{&high_score};

*score_ptr = 86;    // OK
score_ptr = &low_score;    //ERROR

-------------------------------------------------------------------------------------------------------
CASE3:

const int *const pointer(&variable) - data pointed by the pointer is constant and cannot be changed and the pointer itself cannot point somewhere else.

example:

int high_score{100};
int low_score{65};

cont int *const score_ptr{&high_score};

*score_ptr = 86;    // ERROR
score_ptr = &low_score;    //ERROR


-------------------------------------------------------------------------------------------------------

L-values:

values that have names and are adressable ( can be used on the left hand side of an assignment statement)
modifiable if they are not constants

R-value:

(non-adressable and non-assignable)
A value thats not an l-value
are on the right hand side of the assignment expression
a literal
a temporary which is intended to be non-modifiable
