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

#include "section_contents_container.hpp"

using namespace elf;

SectionContentsContainer::SectionContentsContainer(ELFFile *file) : Container(file, true)
{
    setName("Section contents");
}

std::vector<Container *> &SectionContentsContainer::getInnerContainers()
{
    if (innerContainers.empty())
    {
        Container *container;

        container = new Container(getFile(), false, std::make_pair(30, 40));
        container->setName("[test] non-code section");
        addInnerContainer(container);

        container = new CodeContainer(getFile(), std::make_pair(40, 50));
        container->setName("[test] code section");
        addInnerContainer(container);
    }
    return innerContainers;
}

SectionContentsContainer::~SectionContentsContainer() {}
