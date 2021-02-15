#include <string>
#include <cstdlib>

struct sys
{
public:
	std::string m_cwd;
	std::string m_searchDir;
	std::uint16_t m_cores;
	std::uint16_t m_ram;

public:
	sys();
	sys(const sys& other) = delete;
	sys(sys&& other) = delete;

private:
	[[nodiscard]] std::string get_current_dir();
};
