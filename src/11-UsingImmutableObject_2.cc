
// 변수의 값이 변하는 것을 허용치 않으려면 const 키워드를 사용하면 된다, (이미 알고 있다!)

// 일급함수는 함수를 값 취급할 수 있는 것을 의미한다
// 인자값은 _ 지역변수는 그냥
// 값이 계속 생성되어 버린다

// 불변성의 장점
// 1. 외부 상태의 변경 X, 부작용 없다
// 2. 잘못된 객체 상태가 존재하지 않는다. 객체를 새로 만들어 버리기 때문에
// 3. lock 없이 함수 실행 => 스레드에 안전

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