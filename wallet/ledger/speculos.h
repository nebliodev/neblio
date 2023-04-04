#pragma once

#include "comm.h"

#include "hidapi/hidapi.h"

namespace ledger
{
	class Speculos final : public Comm
	{
	public:
		void open() override;
		int send(const bytes &data) override;
		int receive(bytes &rdata) override;
		void close() noexcept override;
		[[nodiscard]] bool isOpen() const override;

	private:
		int sockfd = -1;
		bool opened = false;
	};
} // namespace ledger
