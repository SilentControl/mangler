/* The MIT License (MIT)
 *
 * Copyright (c) 2016 Ștefan-Gabriel Mirea, Adrian Dobrică
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "section_header_table_container.hpp"
#include "sht_entry_container.hpp"

using namespace elf;

SectionHeaderTableContainer::SectionHeaderTableContainer(ELFFile *file,
    const std::pair<int, int> &interval) : Container(file, true, interval)
{
    setName("Section header table");
}

std::vector<Container *> &SectionHeaderTableContainer::getInnerContainers()
{
    if (innerContainers.empty())
    {
        ELFFile *elfHandler = dynamic_cast<ELFFile *>(getFile());
        ELFIO::elfio *elfData = elfHandler->getELFIO();

        for (unsigned int i = 0; i < elfData->get_sections_num(); i++)
        {
            std::pair<int, int> entry_interval;
            entry_interval.first = elfData->get_sections_offset() + i * elfData->get_section_entry_size();
            entry_interval.second = entry_interval.first + elfData->get_section_entry_size();
            SHTEntryContainer *entry = new SHTEntryContainer(elfHandler, entry_interval, i);
            addInnerContainer(entry);

        }
    }
    return innerContainers;
}

SectionHeaderTableContainer::~SectionHeaderTableContainer() {}
