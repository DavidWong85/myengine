#include "Model.h"
#include "VertexArray.h"
#include "VertexBuffer.h"

namespace graphics
{
	struct Face
	{
		glm::vec3 pa;
		glm::vec3 pb;
		glm::vec3 pc;

		glm::vec2 tca;
		glm::vec2 tcb;
		glm::vec2 tcc;

		glm::vec3 na;
		glm::vec3 nb;
		glm::vec3 nc;

		glm::vec2 lmca;
		glm::vec2 lmcb;
		glm::vec2 lmcc;
	};

	Model::Model(std::string path)
	{
		vbp = std::make_shared<VertexBuffer>();
		vbt = std::make_shared<VertexBuffer>();
		vbn = std::make_shared<VertexBuffer>();
		va = std::make_shared<VertexArray>();

		this->vbp = vbp;
		this->vbt = vbt;
		this->vbn = vbn;
		this->va = va;

		std::ifstream f(path.c_str());

		if (!f.is_open())
		{
			throw std::exception();
		}

		std::string line;

		while (!f.eof())
		{
			std::getline(f, line);
		}

		LoadModel(path);
	}

	Model::~Model()
	{
	}

	void Model::SplitStringWhiteSpace(const std::string& input, std::vector<std::string>& output)
	{
		std::string curr;
		output.clear();
		for (size_t i = 0; i < input.length(); i++)
		{
			if (input.at(i) == ' ' ||
				input.at(i) == '\r' ||
				input.at(i) == '\n' ||
				input.at(i) == '\t')
			{
				if (curr.length() > 0)
				{
					output.push_back(curr);
					curr = "";
				}
			}
			else
			{
				curr += input.at(i);
			}
		}
		if (curr.length() > 0)
		{
			output.push_back(curr);
		}
	}

	void Model::SplitString(const std::string& input, char splitter, std::vector<std::string>& output)
	{
		std::string curr;
		output.clear();
		for (size_t i = 0; i < input.length(); i++)
		{
			if (input.at(i) == splitter)
			{
				output.push_back(curr);
				curr = "";
			}
			else
			{
				curr += input.at(i);
			}
		}
		if (curr.length() > 0)
		{
			output.push_back(curr);
		}
	}

	void Model::LoadModel(const std::string& path)
	{
		std::vector<glm::vec3> positions;
		std::vector<glm::vec2> tcs;
		std::vector<glm::vec3> normals;
		std::vector<glm::vec2> lmcs;
		std::vector<Face> faces;

		std::ifstream file(path.c_str());

		if (!file.is_open())
		{
			throw std::exception();
		}

		std::string currentLine;

		while (!file.eof())
		{
			std::getline(file, currentLine);
			if (currentLine.length() < 1) continue;
			std::vector<std::string> tokens;
			Model::SplitStringWhiteSpace(currentLine, tokens);
			if (tokens.size() < 1) continue;

			if (tokens.at(0) == "v")
			{
				glm::vec3 p(atof(tokens.at(1).c_str()), atof(tokens.at(2).c_str()), atof(tokens.at(3).c_str()));
				positions.push_back(p);
			}
			else if (tokens.at(0) == "vt")
			{
				glm::vec2 tc(atof(tokens.at(1).c_str()), 1.0f - atof(tokens.at(2).c_str()));
				tcs.push_back(tc);
			}
			else if (tokens.at(0) == "vn")
			{
				glm::vec3 n(atof(tokens.at(1).c_str()), atof(tokens.at(2).c_str()), atof(tokens.at(3).c_str()));
				normals.push_back(n);
			}
			else if (tokens.at(0) == "f")
			{
				if (tokens.size() < 4) continue;

				Face f;
				std::vector<std::string> sub;
				Model::SplitString(tokens.at(1), '/', sub);
				if (sub.size() >= 1) f.pa = positions.at(atoi(sub.at(0).c_str()) - 1);
				if (sub.size() >= 2) f.tca = tcs.at(atoi(sub.at(1).c_str()) - 1);
				if (sub.size() >= 3) f.na = normals.at(atoi(sub.at(2).c_str()) - 1);
				if (sub.size() >= 4) f.lmca = lmcs.at(atoi(sub.at(3).c_str()) - 1);

				Model::SplitString(tokens.at(2), '/', sub);
				if (sub.size() >= 1) f.pb = positions.at(atoi(sub.at(0).c_str()) - 1);
				if (sub.size() >= 2) f.tcb = tcs.at(atoi(sub.at(1).c_str()) - 1);
				if (sub.size() >= 3) f.nb = normals.at(atoi(sub.at(2).c_str()) - 1);
				if (sub.size() >= 4) f.lmcb = lmcs.at(atoi(sub.at(3).c_str()) - 1);

				Model::SplitString(tokens.at(3), '/', sub);
				if (sub.size() >= 1) f.pc = positions.at(atoi(sub.at(0).c_str()) - 1);
				if (sub.size() >= 2) f.tcc = tcs.at(atoi(sub.at(1).c_str()) - 1);
				if (sub.size() >= 3) f.nc = normals.at(atoi(sub.at(2).c_str()) - 1);
				if (sub.size() >= 4) f.lmcc = lmcs.at(atoi(sub.at(3).c_str()) - 1);

				faces.push_back(f);
				if (tokens.size() < 5) continue;

				Face fq;
				fq.pa = f.pc;
				fq.tca = f.tcc;
				fq.na = f.nc;
				fq.lmca = f.lmcc;

				Model::SplitString(tokens.at(4), '/', sub);
				if (sub.size() >= 1) fq.pb = positions.at(atoi(sub.at(0).c_str()) - 1);
				if (sub.size() >= 2) fq.tcb = tcs.at(atoi(sub.at(1).c_str()) - 1);
				if (sub.size() >= 3) fq.nb = normals.at(atoi(sub.at(2).c_str()) - 1);
				if (sub.size() >= 4) fq.lmcb = lmcs.at(atoi(sub.at(3).c_str()) - 1);

				fq.pc = f.pa;
				fq.tcc = f.tca;
				fq.nc = f.na;
				fq.lmcc = f.lmca;

				faces.push_back(fq);
			}
		}

		if (positions.size() < 1)
		{
			currentLine = "No positions specified";
			throw std::exception();
		}

		{
			for (std::vector<Face>::iterator fit = faces.begin(); fit != faces.end(); fit++)
			{
				vbp->Add(fit->pa);
				vbp->Add(fit->pb);
				vbp->Add(fit->pc);
			}

			va->setBuffer("a_Position", vbp);
		}

		if (tcs.size() > 0)
		{
			for (std::vector<Face>::iterator fit = faces.begin(); fit != faces.end(); fit++)
			{
				vbt->Add(fit->tca);
				vbt->Add(fit->tcb);
				vbt->Add(fit->tcc);
			}

			va->setBuffer("a_TexCoord", vbt);
		}

		if (normals.size() > 0)
		{
			for (std::vector<Face>::iterator fit = faces.begin(); fit != faces.end(); fit++)
			{
				vbn->Add(fit->na);
				vbn->Add(fit->nb);
				vbn->Add(fit->nc);
			}

			va->setBuffer("a_Normal", vbn);
		}

		if (lmcs.size() > 0)
		{
			// TODO
		}
	}

	void Model::Draw()
	{
		glBindVertexArray(va->getID());
		glDrawArrays(GL_TRIANGLES, 0, vbp->getDataSize());
		glBindVertexArray(0);
	}
}