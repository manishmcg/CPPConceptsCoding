#pragma region once
class my_smart_pointer
{
public:
	//explicit my_smart_pointer(int* p);
	explicit my_smart_pointer(double* p);
	~my_smart_pointer();
	double& operator* ();
private:
	double *data;
};
#pragma endregion once

