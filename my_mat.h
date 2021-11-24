#ifndef _my_mat_h_
#define _my_mat_h_

#ifndef _math_h_
#define _math_h_
#endif

#ifndef _limits_h_
#define _limits_h_
#endif

#ifndef _stdio_h_
#define _stdio_h_
#endif

//**initialize global variable type Integer** used if wanted to check by smaller matrix
int extern nRowCol;
//** get new adj matrix by user
void get_matrix (int[][nRowCol]);
//** is there route from a to b
int is_there_route(int[][nRowCol] ,int ,int);
//** return value of route from a to b
int is_shortest_route (int[][nRowCol] ,int ,int);

#endif