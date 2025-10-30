#pragma once
#include <math.h>
#include "progonka.h"

namespace Graph {
	std::vector<double> progonka_data, true_solution, progonka_data2;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ZedGraph;

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
		}

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

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button2;
	private: ZedGraph::ZedGraphControl^ zedGraphControl1;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::DataGridView^ dataGridView3;
private: System::Windows::Forms::ListBox^ listBox1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn6;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn7;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn8;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn9;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn10;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn11;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn12;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn13;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column8;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column9;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn14;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column10;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn15;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn16;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn17;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn18;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ i;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ x_i;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ v_i;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ v2_i;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;
private: System::Windows::Forms::Label^ label11;
private: System::Windows::Forms::TextBox^ textBox11;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ u_i;
	private: ZedGraph::ZedGraphControl^ zedGraphControl2;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker2;
	protected:
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->i = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->x_i = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->u_i = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->v_i = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->zedGraphControl1 = (gcnew ZedGraph::ZedGraphControl());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn11 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn12 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn13 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn18 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn14 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn15 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn16 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn17 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->zedGraphControl2 = (gcnew ZedGraph::ZedGraphControl());
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(278, 364);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(142, 37);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Нарисовать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->i, this->x_i,
					this->u_i, this->v_i, this->Column1
			});
			this->dataGridView1->Location = System::Drawing::Point(973, 30);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->Size = System::Drawing::Size(394, 327);
			this->dataGridView1->TabIndex = 2;
			this->dataGridView1->Visible = false;
			// 
			// i
			// 
			this->i->HeaderText = L"i";
			this->i->MinimumWidth = 6;
			this->i->Name = L"i";
			this->i->ReadOnly = true;
			this->i->Width = 50;
			// 
			// x_i
			// 
			this->x_i->HeaderText = L"x_i";
			this->x_i->MinimumWidth = 6;
			this->x_i->Name = L"x_i";
			this->x_i->ReadOnly = true;
			this->x_i->Width = 75;
			// 
			// u_i
			// 
			this->u_i->HeaderText = L"u_i";
			this->u_i->MinimumWidth = 6;
			this->u_i->Name = L"u_i";
			this->u_i->ReadOnly = true;
			this->u_i->Width = 75;
			// 
			// v_i
			// 
			this->v_i->HeaderText = L"v_i";
			this->v_i->MinimumWidth = 6;
			this->v_i->Name = L"v_i";
			this->v_i->Width = 75;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"u_i - v_i";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->Width = 75;
			// 
			// Column2
			// 
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->Name = L"Column4";
			// 
			// Column5
			// 
			this->Column5->Name = L"Column5";
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"u_i";
			this->Column6->MinimumWidth = 6;
			this->Column6->Name = L"Column6";
			this->Column6->Width = 75;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"u_i - v_i";
			this->Column7->MinimumWidth = 6;
			this->Column7->Name = L"Column7";
			this->Column7->Width = 75;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(426, 365);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(142, 36);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Масштабировать";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// zedGraphControl1
			// 
			this->zedGraphControl1->Location = System::Drawing::Point(22, 30);
			this->zedGraphControl1->Margin = System::Windows::Forms::Padding(4);
			this->zedGraphControl1->Name = L"zedGraphControl1";
			this->zedGraphControl1->ScrollGrace = 0;
			this->zedGraphControl1->ScrollMaxX = 0;
			this->zedGraphControl1->ScrollMaxY = 0;
			this->zedGraphControl1->ScrollMaxY2 = 0;
			this->zedGraphControl1->ScrollMinX = 0;
			this->zedGraphControl1->ScrollMinY = 0;
			this->zedGraphControl1->ScrollMinY2 = 0;
			this->zedGraphControl1->Size = System::Drawing::Size(431, 287);
			this->zedGraphControl1->TabIndex = 0;
			this->zedGraphControl1->GraphPane->Title->Text = "";
			this->zedGraphControl1->GraphPane->XAxis->Title->Text = "";
			this->zedGraphControl1->GraphPane->YAxis->Title->Text = "";
			this->zedGraphControl1->Load += gcnew System::EventHandler(this, &MyForm::zedGraphControl1_Load);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton1->Location = System::Drawing::Point(25, 478);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(139, 21);
			this->radioButton1->TabIndex = 32;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Тестовая задача";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButtons_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton2->Location = System::Drawing::Point(22, 505);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(142, 21);
			this->radioButton2->TabIndex = 33;
			this->radioButton2->Text = L"Основная задача";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButtons_CheckedChanged);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label13->Location = System::Drawing::Point(586, 383);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(381, 156);
			this->label13->TabIndex = 35;
			this->label13->Text = resources->GetString(L"label13.Text");
			this->label13->Click += gcnew System::EventHandler(this, &MyForm::label13_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(131, 364);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(142, 37);
			this->button3->TabIndex = 14;
			this->button3->Text = L"Вычислить";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label14->Location = System::Drawing::Point(586, 383);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(291, 156);
			this->label14->TabIndex = 36;
			this->label14->Text = resources->GetString(L"label14.Text");
			this->label14->Visible = false;
			this->label14->Click += gcnew System::EventHandler(this, &MyForm::label14_Click);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label16->Location = System::Drawing::Point(586, 365);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(117, 16);
			this->label16->TabIndex = 38;
			this->label16->Text = L"Текущая задача:";
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4, this->dataGridViewTextBoxColumn5
			});
			this->dataGridView2->Location = System::Drawing::Point(973, 30);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersVisible = false;
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->Size = System::Drawing::Size(405, 327);
			this->dataGridView2->TabIndex = 43;
			this->dataGridView2->Visible = false;
			this->dataGridView2->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView2_CellContentClick);
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"i";
			this->dataGridViewTextBoxColumn1->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			this->dataGridViewTextBoxColumn1->Width = 50;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"x_i";
			this->dataGridViewTextBoxColumn2->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->ReadOnly = true;
			this->dataGridViewTextBoxColumn2->Width = 75;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"v_i";
			this->dataGridViewTextBoxColumn3->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->ReadOnly = true;
			this->dataGridViewTextBoxColumn3->Width = 75;
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->HeaderText = L"v2_i";
			this->dataGridViewTextBoxColumn4->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			this->dataGridViewTextBoxColumn4->Width = 75;
			// 
			// dataGridViewTextBoxColumn5
			// 
			this->dataGridViewTextBoxColumn5->HeaderText = L"v_i - v2_i";
			this->dataGridViewTextBoxColumn5->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			this->dataGridViewTextBoxColumn5->Width = 75;
			// 
			// dataGridViewTextBoxColumn6
			// 
			this->dataGridViewTextBoxColumn6->Name = L"dataGridViewTextBoxColumn6";
			// 
			// dataGridViewTextBoxColumn7
			// 
			this->dataGridViewTextBoxColumn7->Name = L"dataGridViewTextBoxColumn7";
			// 
			// dataGridViewTextBoxColumn8
			// 
			this->dataGridViewTextBoxColumn8->Name = L"dataGridViewTextBoxColumn8";
			// 
			// dataGridViewTextBoxColumn9
			// 
			this->dataGridViewTextBoxColumn9->Name = L"dataGridViewTextBoxColumn9";
			// 
			// dataGridView3
			// 
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->dataGridViewTextBoxColumn10,
					this->dataGridViewTextBoxColumn11, this->dataGridViewTextBoxColumn12, this->dataGridViewTextBoxColumn13, this->Column8, this->Column9,
					this->dataGridViewTextBoxColumn18
			});
			this->dataGridView3->Location = System::Drawing::Point(973, 30);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->RowHeadersVisible = false;
			this->dataGridView3->RowHeadersWidth = 51;
			this->dataGridView3->Size = System::Drawing::Size(352, 327);
			this->dataGridView3->TabIndex = 44;
			this->dataGridView3->Visible = false;
			// 
			// dataGridViewTextBoxColumn10
			// 
			this->dataGridViewTextBoxColumn10->HeaderText = L"i";
			this->dataGridViewTextBoxColumn10->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn10->Name = L"dataGridViewTextBoxColumn10";
			this->dataGridViewTextBoxColumn10->ReadOnly = true;
			this->dataGridViewTextBoxColumn10->Width = 50;
			// 
			// dataGridViewTextBoxColumn11
			// 
			this->dataGridViewTextBoxColumn11->HeaderText = L"x_i";
			this->dataGridViewTextBoxColumn11->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn11->Name = L"dataGridViewTextBoxColumn11";
			this->dataGridViewTextBoxColumn11->ReadOnly = true;
			this->dataGridViewTextBoxColumn11->Width = 75;
			// 
			// dataGridViewTextBoxColumn12
			// 
			this->dataGridViewTextBoxColumn12->HeaderText = L"u_i";
			this->dataGridViewTextBoxColumn12->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn12->Name = L"dataGridViewTextBoxColumn12";
			this->dataGridViewTextBoxColumn12->ReadOnly = true;
			this->dataGridViewTextBoxColumn12->Width = 75;
			// 
			// dataGridViewTextBoxColumn13
			// 
			this->dataGridViewTextBoxColumn13->HeaderText = L"v_i";
			this->dataGridViewTextBoxColumn13->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn13->Name = L"dataGridViewTextBoxColumn13";
			this->dataGridViewTextBoxColumn13->Width = 75;
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"u\'_i";
			this->Column8->MinimumWidth = 6;
			this->Column8->Name = L"Column8";
			this->Column8->Width = 75;
			// 
			// Column9
			// 
			this->Column9->HeaderText = L"v\'_i";
			this->Column9->MinimumWidth = 6;
			this->Column9->Name = L"Column9";
			this->Column9->Width = 75;
			// 
			// dataGridViewTextBoxColumn18
			// 
			this->dataGridViewTextBoxColumn18->Name = L"dataGridViewTextBoxColumn18";
			// 
			// dataGridViewTextBoxColumn14
			// 
			this->dataGridViewTextBoxColumn14->HeaderText = L"v_i - v2_i";
			this->dataGridViewTextBoxColumn14->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn14->Name = L"dataGridViewTextBoxColumn14";
			this->dataGridViewTextBoxColumn14->Width = 75;
			// 
			// Column10
			// 
			this->Column10->HeaderText = L"v\'i - v\'2_i";
			this->Column10->MinimumWidth = 6;
			this->Column10->Name = L"Column10";
			this->Column10->Width = 75;
			// 
			// dataGridViewTextBoxColumn15
			// 
			this->dataGridViewTextBoxColumn15->Name = L"dataGridViewTextBoxColumn15";
			// 
			// dataGridViewTextBoxColumn16
			// 
			this->dataGridViewTextBoxColumn16->Name = L"dataGridViewTextBoxColumn16";
			// 
			// dataGridViewTextBoxColumn17
			// 
			this->dataGridViewTextBoxColumn17->Name = L"dataGridViewTextBoxColumn17";
			// 
			// listBox1
			// 
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"Справочная информация" });
			this->listBox1->Location = System::Drawing::Point(973, 363);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(409, 180);
			this->listBox1->TabIndex = 45;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(35, 375);
			this->label11->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(13, 13);
			this->label11->TabIndex = 26;
			this->label11->Text = L"n";
			this->label11->Click += gcnew System::EventHandler(this, &MyForm::label11_Click);
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(52, 372);
			this->textBox11->Margin = System::Windows::Forms::Padding(2);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(54, 20);
			this->textBox11->TabIndex = 25;
			this->textBox11->Text = L"10000";
			this->textBox11->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox11_TextChanged);
			// 
			// zedGraphControl2
			// 
			this->zedGraphControl2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->zedGraphControl2->Location = System::Drawing::Point(477, 30);
			this->zedGraphControl2->Margin = System::Windows::Forms::Padding(4);
			this->zedGraphControl2->Name = L"zedGraphControl2";
			this->zedGraphControl2->ScrollGrace = 0;
			this->zedGraphControl2->ScrollMaxX = 0;
			this->zedGraphControl2->ScrollMaxY = 0;
			this->zedGraphControl2->ScrollMaxY2 = 0;
			this->zedGraphControl2->ScrollMinX = 0;
			this->zedGraphControl2->ScrollMinY = 0;
			this->zedGraphControl2->ScrollMinY2 = 0;
			this->zedGraphControl2->Size = System::Drawing::Size(439, 287);
			this->zedGraphControl2->TabIndex = 46;
			this->zedGraphControl2->GraphPane->Title->Text = "";
			this->zedGraphControl2->GraphPane->XAxis->Title->Text = "";
			this->zedGraphControl2->GraphPane->YAxis->Title->Text = "";
			this->zedGraphControl2->Load += gcnew System::EventHandler(this, &MyForm::zedGraphControl2_Load);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1443, 544);
			this->Controls->Add(this->zedGraphControl2);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->textBox11);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->zedGraphControl1);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->dataGridView3);
			this->Name = L"MyForm";
			this->Text = L"Моё окно";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		double f1(double x) {
			return sin(x);
		}

		double f2(double x) {
			return sin(2 * x);
		}


	private: System::Void zedGraphControl1_Load(System::Object^ sender, System::EventArgs^ e) {
	}


		   bool can_draw = false;

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (can_draw) {

			GraphPane^ panel = zedGraphControl1->GraphPane;
			GraphPane^ panel2 = zedGraphControl2->GraphPane;
			panel->CurveList->Clear();
			panel2->CurveList->Clear();
			PointPairList^ f1_list = gcnew ZedGraph::PointPairList();
			PointPairList^ f2_list = gcnew ZedGraph::PointPairList();
			PointPairList^ f3_list = gcnew ZedGraph::PointPairList();
			dataGridView1->Visible = false;
			dataGridView2->Visible = false;
			dataGridView3->Visible = false;
			
			int i = 0;
			double mx = -1., xe = -1.;
			int count_it = progonka_data.size();
			if (num_rhs == 1) {
				dataGridView1->Visible = true;
				dataGridView1->Rows->Clear();
				
				for (i = 0; i < count_it; ++i)
				{

					f1_list->Add(double(i) / progonka_data.size(), progonka_data[i]);
					f2_list->Add(double(i) / true_solution.size(), true_solution[i]);
					f3_list->Add(double(i) / true_solution.size(), progonka_data[i] - true_solution[i]);
					
					
					if (abs(progonka_data[i] - true_solution[i]) > mx)
					{
						mx = abs(progonka_data[i] - true_solution[i]);
						xe = (double(i)) / true_solution.size();
					}
  
					dataGridView1->Rows->Add();

					dataGridView1->Rows[i]->Cells[0]->Value = i;
					dataGridView1->Rows[i]->Cells[1]->Value = (double(i) / progonka_data.size()).ToString("E3");
					dataGridView1->Rows[i]->Cells[2]->Value = (progonka_data[i]).ToString("E3");
					dataGridView1->Rows[i]->Cells[3]->Value = (true_solution[i]).ToString("E3");
					dataGridView1->Rows[i]->Cells[4]->Value = (progonka_data[i] - true_solution[i]).ToString("E3");
				}
			}

			if (num_rhs == 2) {
				dataGridView2->Visible = true;
				dataGridView2->Rows->Clear();
				for (i = 0; i < count_it; ++i)
				{
					f1_list->Add(double(i) / progonka_data.size(), progonka_data[i]);
					f2_list->Add(double(i) / progonka_data.size(), progonka_data2[2 * i]);
					f3_list->Add(double(i) / true_solution.size(), progonka_data[i] - progonka_data2[2 * i]);

					if (abs(progonka_data[i] - progonka_data2[2 * i]) > mx)
					{
						mx = abs(progonka_data[i] - progonka_data2[2 * i]);
						xe = (double(i)) / true_solution.size();
					}

					dataGridView2->Rows->Add();

					dataGridView2->Rows[i]->Cells[0]->Value = i;
					dataGridView2->Rows[i]->Cells[1]->Value = (double(i) / progonka_data.size()).ToString("E3");
					dataGridView2->Rows[i]->Cells[2]->Value = (progonka_data[i]).ToString("E3");
					dataGridView2->Rows[i]->Cells[3]->Value = (progonka_data2[2*i]).ToString("E3");
					dataGridView2->Rows[i]->Cells[4]->Value = (progonka_data[i] - progonka_data2[2 * i]).ToString("E3");

					
				}
			}
			LineItem Curve1 = panel->AddCurve("численное решение", f1_list, Color::Red, SymbolType::Plus);
			listBox1->Items->Clear();
			if (num_rhs == 2)
			{
				LineItem CurvE3 = panel->AddCurve("численное решение с половинным шагом", f2_list, Color::Blue, SymbolType::Circle);
				LineItem CurvE2 = panel2->AddCurve("разность численных решений в общих узлах", f3_list, Color::Green, SymbolType::Circle);
				listBox1->Items->Add("Для решения задачи использована равномерная");
				listBox1->Items->Add("сетка c числом разбиений n = " + (count_it - 1).ToString() + ";");
				listBox1->Items->Add("Задача должна быть решена с заданной");
				listBox1->Items->Add("точностью e = 5E–007; задача решена");
				listBox1->Items->Add("с точночтью e2 = " + (mx).ToString("E3") + ";");
				listBox1->Items->Add("Максимальня разность численных решений");
				listBox1->Items->Add("в общих узлах сетки наблюдается в точке");
				listBox1->Items->Add("x = " + (xe).ToString("E3"));
			}
			if (num_rhs == 1)
			{
				LineItem CurvE3 = panel->AddCurve("аналитическое решение", f2_list, Color::Blue, SymbolType::Circle);
				LineItem CurvE2 = panel2->AddCurve("разность аналитического и численного решения", f3_list, Color::Green, SymbolType::Circle);
				listBox1->Items->Add("Для решения задачи использована равномерная");
				listBox1->Items->Add("сетка c числом разбиений n = " + (count_it - 1).ToString() + ";");
				listBox1->Items->Add("Задача должна быть решена с погрешностью");
				listBox1->Items->Add("не более e = 5E–007; задача решена");
				listBox1->Items->Add("с погрешностью e1 = " + (mx).ToString("E3") + ";");
				listBox1->Items->Add("Максимальное отклонение аналитического");
				listBox1->Items->Add("и численного решений наблюдается в точке");
				listBox1->Items->Add("x = " + (xe).ToString("E3"));
			}
			if (panel->ZoomStack != nullptr)
			{
				panel->ZoomStack->Clear();
			}
			panel->XAxis->Title->Text = "X ось";
			panel->YAxis->Title->Text = "V ось";
			panel->YAxis->Scale->MinAuto = true;
			panel->YAxis->Scale->MaxAuto = true;

			if (panel2->ZoomStack != nullptr)
			{
				panel2->ZoomStack->Clear();
			}
			panel2->XAxis->Title->Text = "X ось";
			panel2->YAxis->Title->Text = "V ось";
			panel2->YAxis->Scale->MinAuto = true;
			panel2->YAxis->Scale->MaxAuto = true;


			zedGraphControl1->AxisChange();
			zedGraphControl1->Refresh();
			zedGraphControl1->Invalidate();
			zedGraphControl2->AxisChange();
			zedGraphControl2->Refresh();
			zedGraphControl2->Invalidate();
		}
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		GraphPane^ panel = zedGraphControl1->GraphPane;

		if (panel->ZoomStack != nullptr)
		{
			panel->ZoomStack->Clear();
		}
		panel->YAxis->Scale->MinAuto = true;
		panel->YAxis->Scale->MaxAuto = true;


		zedGraphControl1->AxisChange();
		zedGraphControl1->Refresh();
		zedGraphControl1->Invalidate();

		GraphPane^ panel2 = zedGraphControl2->GraphPane;

		if (panel2->ZoomStack != nullptr)
		{
			panel2->ZoomStack->Clear();
		}
		panel2->YAxis->Scale->MinAuto = true;
		panel2->YAxis->Scale->MaxAuto = true;


		zedGraphControl2->AxisChange();
		zedGraphControl2->Refresh();
		zedGraphControl2->Invalidate();

	}

int num_rhs = 1;
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		long long n = Convert::ToInt64(textBox11->Text);
		if (num_rhs == 1)
		{
			true_solution = get_true_solution(n);
			progonka_data = calc_test_task(n);
		}
		else if (num_rhs == 2)
		{
			progonka_data = calc_main_task(n);
			progonka_data2 = calc_main_task(2 * n);
		}
		can_draw = true;
	}


	private: System::Void radioButtons_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		GraphPane^ panel = zedGraphControl1->GraphPane;
		listBox1->Items->Clear();
		panel->CurveList->Clear();
		zedGraphControl1->AxisChange();
		zedGraphControl1->Invalidate();
		GraphPane^ panel2 = zedGraphControl2->GraphPane;
		panel2->CurveList->Clear();
		zedGraphControl2->AxisChange();
		zedGraphControl2->Invalidate();

		can_draw = false;
		dataGridView1->Visible = false;
		dataGridView2->Visible = false;
		dataGridView3->Visible = false;
		label13->Visible = false;
		label14->Visible = false;
		this->button1->Visible = false;
		if (radioButton1->Checked) {
			
			label13->Visible = true;
			num_rhs = 1;
			this->button1->Visible = true;
		}
		if (radioButton2->Checked) {
			label14->Visible = true;
			this->button1->Visible = true;
			num_rhs = 2;
		}
	}


private: System::Void textBox7_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	if (can_draw) {
		
	}
}
private: System::Void label15_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox13_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label14_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void dataGridView2_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox14_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label11_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox11_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label13_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void zedGraphControl2_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
