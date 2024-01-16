#pragma once
class Color
{
private:
	float red;
	float green;
	float blue;

public:
	Color() : red(0.0), green(0.0), blue(0.0) {};
	Color(float dred, float dgreen, float dblue){
		this->setRed(dred);
		this->setGreen(dgreen);
		this->setBlue(dblue);
	};
	
	inline float getRed() const { return this->red; }
	inline float getGreen() const { return this->green; }
	inline float getBlue() const { return this->blue; }

	inline void setRed(const float& RedtoSet) { 
		if (RedtoSet >= 1) this->red = 1.0;
		else this->red = RedtoSet;
	}
	inline void setGreen(const float& GreentoSet) { 
		if (GreentoSet >= 1) this->green = 1.0;
		else this->green = GreentoSet;
	}
	inline void setBlue(const float& BluetoSet) { 
		if (BluetoSet >= 1) this->blue = 1.0;
		else this->blue = BluetoSet;
	}

};

