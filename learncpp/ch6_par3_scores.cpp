#include <iostream>

int main()
{
	int scores[] = {84, 92, 76, 81, 56};
	const int numStudents = sizeof(scores)/sizeof(scores[0]);

	int index_maxScore = 0;

	//now look for a largest score
	for (int student=1; student<numStudents; ++student)
	{
		if (scores[student]>scores[index_maxScore])
		{
			index_maxScore = student;
		}
	}

	std::cout << "The best score was: " << scores[index_maxScore] << std::endl;


	return 0;
}