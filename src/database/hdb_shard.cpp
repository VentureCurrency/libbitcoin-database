/*
 * Copyright (c) 2011-2013 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin.
 *
 * libbitcoin is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include <bitcoin/blockchain/database/hdb_shard.hpp>

#include <bitcoin/utility/assert.hpp>

namespace libbitcoin {
    namespace blockchain {

hdb_shard::hdb_shard(mmfile& file, const hdb_shard_settings& settings)
  : file_(file), settings_(settings)
{
}

void hdb_shard::initialize_new()
{
    constexpr size_t total_size = 8 + 8 * shard_max_entries;
    reserve(total_size);
}

void hdb_shard::reserve(size_t size)
{
    BITCOIN_ASSERT(size > file_.size());
    bool success = file_.resize(size);
    BITCOIN_ASSERT(success);
}

    } // namespace blockchain
} // namespace libbitcoin

