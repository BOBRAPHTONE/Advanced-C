"""
if (!(keyBegin < keyEnd))

            return;

        auto nextInterval = --m_map.upper_bound(keyEnd);

        auto inserted1 = m_map.end();

        auto inserted2 = m_map.end();

        assert(nextInterval != m_map.end());

        if (nextInterval->second == val)

            ++nextInterval;

        else if (nextInterval->first < keyEnd)

        {

            const V & nextValue = nextInterval->second;

            ++nextInterval;

            inserted1 = nextInterval = m_map.emplace_hint(nextInterval, keyEnd, nextValue);

        }

        try

        {

            auto prevInterval = nextInterval;

            --prevInterval;

            assert(prevInterval != m_map.end());

            if (keyBegin < prevInterval->first)

                prevInterval = --m_map.upper_bound(keyBegin);

            assert(prevInterval != m_map.end());

            if (!(prevInterval->second == val))

            {

                if (prevInterval->first < keyBegin)

                {

                    ++prevInterval;

                    inserted2 = prevInterval = m_map.emplace_hint(prevInterval, keyBegin, val);

                }

                else

                {

                    auto beforePrev = prevInterval;

                    --beforePrev;

                    if (beforePrev != m_map.end() && beforePrev->second == val)

                        prevInterval = beforePrev;

                    else

                    {

                        assert(prevInterval != m_map.end());

                        assert(prevInterval != nextInterval);

                        auto hint = m_map.erase(prevInterval);

                        inserted2 = prevInterval = m_map.emplace_hint(hint, keyBegin, val);

                    }

                }

            }

            assert(prevInterval != m_map.end());

            m_map.erase(++prevInterval, nextInterval);

        }

        catch (...)

        {

            if (inserted1 != m_map.end())

                m_map.erase(inserted1);

            if (inserted2 != m_map.end())

                m_map.erase(inserted2);

            throw;

        }
"""