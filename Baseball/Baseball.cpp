#include <stdexcept>
#include <string>

using namespace std;

struct Result {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& question)
		: question(question) {
	}

	Result guess(string guessNumber) {
		assertIllegalArgument(guessNumber);

		if (guessNumber == question) {
			return { true, 3, 0 };
		}

		bool solved = false;
		int strikes = getStrikesCount(guessNumber);
		int balls = getBallsCount(guessNumber);

		return { solved,strikes,balls };
	}

private:

	bool isDuplicatedNumber(string guessNumber) {
		return guessNumber[0] == guessNumber[1] ||
			guessNumber[0] == guessNumber[2] ||
			guessNumber[1] == guessNumber[2];
	}

	bool isIncludeChar(const string& guessNumber) {
		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			return true;
		}
		return false;
	}

	void assertIllegalArgument(string guessNumber) {
		if (guessNumber == "") {
			throw std::invalid_argument("���� �־����");
		}
		if (guessNumber.length() != 3) {
			throw std::invalid_argument("�ڸ��� ����");
		}
		if (isIncludeChar(guessNumber)) {
			throw std::invalid_argument("���ڷθ� �����Ǿ� ���� ����");
		}
		if (isDuplicatedNumber(guessNumber)) {
			throw std::invalid_argument("�ߺ��� ����");
		}
	}

	int getStrikesCount(string guessNumber)
	{
		int strikes = 0;

		for (int i = 0; i < 3; i++)
		{
			if (guessNumber[i] == question[i])
			{
				strikes++;

			}
		}

		return strikes;
	}

	int getBallsCount(const string& guessNumber)
	{
		int ballcounts = 0;

		for (int i = 0; i < 3; i++)
		{
			int index = question.find(guessNumber[i]);
			if (index == -1) continue;
			if (index == i) continue;
			ballcounts++;
		}

		return ballcounts;
	}

	string question;
};
