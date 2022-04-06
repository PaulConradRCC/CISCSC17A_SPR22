class CComplex
{
	private:
		float real, imag;
		
	public:
		CComplex(float r, float im)
		{
			real = r;
			imag = im;
		}
		
		float getReal() const
		{
			return real;
		}
		
		float getImaginary() const
		{
			return imag;
		}
		
		CComplex operator+(const CComplex &rt)
		{
			return CComplex( this->getReal() + rt.getReal(), 
							 this->getImaginary() + rt.getImaginary() );
		}
};