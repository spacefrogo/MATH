### 203hotline

Subject:

Uncle Luigi runs a 25-phone hotline in Pondicherry. He reckons 3500 people could possibly call during
each 8-hour day, and would like to know the probability of an overload (that is, the probability of no line
being available), depending on the average duration of calls.

The random variable representing the number of people calling at a given time follows the binomial distribution, with calls being independent from each other. You’re also thinking about estimating the binomial
ditribution with a Poisson distribution, so it can be used on a larger scale.
Your first task is to compute the binomial coefficient (k / n) given k and n (emphasizing the computation speed
and stack optimization).


Your second task is to compare the binomial and Poisson distributions, given the average duration of calls,
by printing:

• the probabilities of getting n simultaneous calls (for n increasing from 0 to 50),

• the probability of an overload,

• the computation time


USAGE:

./203hotline [n k | d]

DESCRIPTION

• n value for the computation of C(n, k)

• k value for the computation of C(n, k)

• d average duration of calls (in seconds)

Example:

![image](https://user-images.githubusercontent.com/65818912/158599745-3868df86-310f-4a50-87d1-6e3d49f008aa.png)


