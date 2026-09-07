from dummy_python_project.main import add, return_forty_two, return_true


def test_add():
    assert add(2, 3) == 5
    assert add(-1, 1) == 0
    assert add(0, 0) == 0


def test_return_forty_two():
    assert return_forty_two() == 42


def test_return_true():
    assert return_true() is True
