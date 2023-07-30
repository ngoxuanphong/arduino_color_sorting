#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
namespace Color_Sorting_Arduino {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			findPort();
		}
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ button1;
	public:

	public:
		String^ RxString;
	private: System::Windows::Forms::Button^ button0;
	public:
	private: System::Windows::Forms::TextBox^ textBox0;
	private: System::Windows::Forms::TextBox^ textBox5;

	public:
		String^ RyString;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ butConnect;

	private: System::Windows::Forms::Button^ butStop;



	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;


	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::IO::Ports::SerialPort^ serialPort1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Button^ butStart;
	private: System::Windows::Forms::Label^ label2;
	private: System::ComponentModel::IContainer^ components;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->butConnect = (gcnew System::Windows::Forms::Button());
			this->butStop = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->butStart = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button0 = (gcnew System::Windows::Forms::Button());
			this->textBox0 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(196, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(711, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"HỆ THÔNG PHÂN LOẠI SẢN PHẨM THEO MÀU SẮC";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(981, 80);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(78, 21);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// butConnect
			// 
			this->butConnect->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->butConnect->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->butConnect->Location = System::Drawing::Point(792, 142);
			this->butConnect->Name = L"butConnect";
			this->butConnect->Size = System::Drawing::Size(176, 47);
			this->butConnect->TabIndex = 2;
			this->butConnect->Text = L"CONNECT";
			this->butConnect->UseVisualStyleBackColor = false;
			this->butConnect->Click += gcnew System::EventHandler(this, &MyForm::butConnect_Click);
			// 
			// butStop
			// 
			this->butStop->BackColor = System::Drawing::Color::Red;
			this->butStop->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->butStop->Location = System::Drawing::Point(792, 315);
			this->butStop->Name = L"butStop";
			this->butStop->Size = System::Drawing::Size(178, 56);
			this->butStop->TabIndex = 4;
			this->butStop->Text = L"STOP";
			this->butStop->UseVisualStyleBackColor = false;
			this->butStop->Click += gcnew System::EventHandler(this, &MyForm::butStop_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Green;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(176, 142);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(176, 47);
			this->button4->TabIndex = 5;
			this->button4->Text = L"GREEN";
			this->button4->UseVisualStyleBackColor = false;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::Red;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(176, 213);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(176, 47);
			this->button5->TabIndex = 6;
			this->button5->Text = L"RED";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::Yellow;
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(176, 292);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(176, 47);
			this->button6->TabIndex = 7;
			this->button6->Text = L"YELLOW";
			this->button6->UseVisualStyleBackColor = false;
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::Blue;
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(176, 363);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(176, 47);
			this->button7->TabIndex = 8;
			this->button7->Text = L"BLUE";
			this->button7->UseVisualStyleBackColor = false;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(395, 156);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(70, 20);
			this->textBox1->TabIndex = 11;
			this->textBox1->Text = L"00";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// serialPort1
			// 
			this->serialPort1->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &MyForm::serialPort1_DataReceived);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(395, 225);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(70, 20);
			this->textBox2->TabIndex = 12;
			this->textBox2->Text = L"00";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(395, 306);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(70, 20);
			this->textBox3->TabIndex = 13;
			this->textBox3->Text = L"00";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(395, 377);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(70, 20);
			this->textBox4->TabIndex = 14;
			this->textBox4->Text = L"00";
			// 
			// butStart
			// 
			this->butStart->BackColor = System::Drawing::Color::Green;
			this->butStart->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->butStart->Location = System::Drawing::Point(792, 225);
			this->butStart->Name = L"butStart";
			this->butStart->Size = System::Drawing::Size(175, 58);
			this->butStart->TabIndex = 15;
			this->butStart->Text = L"START";
			this->butStart->UseVisualStyleBackColor = false;
			this->butStart->Click += gcnew System::EventHandler(this, &MyForm::butStart_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(975, 492);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 31);
			this->label2->TabIndex = 16;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Yellow;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(792, 400);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(178, 56);
			this->button1->TabIndex = 17;
			this->button1->Text = L"RESET";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::butRESET);
			// 
			// button0
			// 
			this->button0->BackColor = System::Drawing::Color::White;
			this->button0->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button0->Location = System::Drawing::Point(176, 436);
			this->button0->Name = L"button0";
			this->button0->Size = System::Drawing::Size(176, 47);
			this->button0->TabIndex = 18;
			this->button0->Text = L"NAN";
			this->button0->UseVisualStyleBackColor = false;
			// 
			// textBox0
			// 
			this->textBox0->Location = System::Drawing::Point(395, 450);
			this->textBox0->Name = L"textBox0";
			this->textBox0->Size = System::Drawing::Size(70, 20);
			this->textBox0->TabIndex = 19;
			this->textBox0->Text = L"00";
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::SystemColors::HotTrack;
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox5->Location = System::Drawing::Point(792, 80);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(162, 24);
			this->textBox5->TabIndex = 20;
			this->textBox5->Text = L"CỔNG KẾT NỐI";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1254, 640);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox0);
			this->Controls->Add(this->button0);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->butStart);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->butStop);
			this->Controls->Add(this->butConnect);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void findPort(void)
	{
		array<Object^>^ objectArray = serialPort1->GetPortNames();
		this->comboBox1->Items->AddRange(objectArray);
	}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	this->serialPort1->ReadLine();
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void butConnect_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->comboBox1->Text == String::Empty) {
		MessageBox::Show("Please select port settings");
	}
	else {
		try {
			if (!this->serialPort1->IsOpen) {
				this->serialPort1->PortName = this->comboBox1->Text;
				this->serialPort1->BaudRate = 9600;
				this->serialPort1->Open();
				this->label2->Text = "CONNECTED";
				this->serialPort1->WriteLine("R");

			}
			else {
				MessageBox::Show("Port isn't opened");
			}
		}
		catch (UnauthorizedAccessException^) {
			MessageBox::Show("UnauthorizedAccessException");
		}
	}
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void butStop_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->serialPort1->IsOpen) {
		this->serialPort1->WriteLine("T");
		this->label2->Text = "STOPPED";
	}
}
private: System::Void butStart_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->serialPort1->IsOpen) {
		this->serialPort1->WriteLine("B");
		this->label2->Text = "STARTED";
	}
}
private: System::Void butRESET(System::Object^ sender, System::EventArgs^ e) {
	if (this->serialPort1->IsOpen) {
		this->serialPort1->WriteLine("R");
		this->label2->Text = "STOPPED";
	}
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void serialPort1_DataReceived(System::Object^ sender,
	System::IO::Ports::SerialDataReceivedEventArgs^ e) {
	RxString = serialPort1->ReadExisting();
	this->Invoke(gcnew EventHandler(this, &MyForm::DisplayText));
	System::Threading::Thread::Sleep(1000);
}

private: System::Void DisplayText(System::Object^ sender, System::EventArgs^ e) {
	String^ length1;
	length1 = RxString->Length.ToString();
	if (RxString != "") {
		textBox0->Text = RxString->Substring(4, 2); // id 0, mau bo di
		textBox1->Text = RxString->Substring(7, 2); // id 1, mau green
		textBox2->Text = RxString->Substring(10, 2); // id 2, mau red
		textBox3->Text = RxString->Substring(13, 2); // id 3, mau yellow
		textBox4->Text = RxString->Substring(16, 2); // id 4, mau blue

	}
}

};
}
