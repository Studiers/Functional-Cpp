
// ������ ���� ���ϴ� ���� ���ġ �������� const Ű���带 ����ϸ� �ȴ�, (�̹� �˰� �ִ�!)

// �ϱ��Լ��� �Լ��� �� ����� �� �ִ� ���� �ǹ��Ѵ�
// ���ڰ��� _ ���������� �׳�
// ���� ��� �����Ǿ� ������

// �Һ����� ����
// 1. �ܺ� ������ ���� X, ���ۿ� ����
// 2. �߸��� ��ü ���°� �������� �ʴ´�. ��ü�� ���� ����� ������ ������
// 3. lock ���� �Լ� ���� => �����忡 ����

#include <iostream>

class ImmutableObject {
private:
	const std::string m_name;
	const int m_studentNumber;

public:
	ImmutableObject(const std::string& _name, const int _studentNumber) :
		m_name(_name),
		m_studentNumber(_studentNumber) {}

	const ImmutableObject SetName(const std::string &_name) const {
		return ImmutableObject(_name, m_studentNumber);
	}

	const ImmutableObject SetStudentNumber(const int& _studentNumber) const {
		return ImmutableObject(m_name, _studentNumber);
	}

	inline std::string Name() {
		return m_name;
	}

	inline int StudentNumber() {
		return m_studentNumber;
	}
};

auto main(void) -> int {
	const std::string name = "My Name", new_name = "Your Name";
	const int studentNumber = 1, new_studentNumber = 1;

	const ImmutableObject immutableObject(name, studentNumber);
	const ImmutableObject immutableObjectRenamed = immutableObject.SetName(new_name);
	const ImmutableObject immutableObjectReStudent = immutableObject.SetName(new_name);

	return 0;
}