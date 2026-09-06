from dummy_python_project.main import add, returnFourtyTwo, returnTrue


def test_add():
    assert add(2, 3) == 5
    assert add(-1, 1) == 0
    assert add(0, 0) == 0


def test_returnFourtyTwo():
    assert returnFourtyTwo() == 42


def test_returnTrue():
    assert returnTrue() is True
