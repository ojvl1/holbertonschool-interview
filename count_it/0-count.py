#!/usr/bin/python3

import requests


def count_words(subreddit, word_list, after=None,
                counts=None, processed_words=None):
    if counts is None:
        # Initial call: process word_list
        # and initialize counts and processed_words
        counts = {}
        processed_words = {}
        for word in word_list:
            lower_word = word.lower()
            processed_words[lower_word] = processed_words.get(lower_word, 0)
            + 1
    else:
        # Ensure processed_words is not None in recursive calls
        if processed_words is None:
            processed_words = {}

    headers = {'User-Agent': 'python:count_it:v1.0 (by /u/yourusername)'}
    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    params = {'limit': 100}
    if after:
        params['after'] = after

    response = requests.get(url, headers=headers,
                            params=params, allow_redirects=False)

    if response.status_code != 200:
        return

    data = response.json()

    for article in data['data']['children']:
        title = article['data']['title']
        for word in title.split():
            lower_word = word.lower()
            if lower_word in processed_words:
                counts[lower_word] = counts.get(lower_word, 0)
                + processed_words[lower_word]

    new_after = data['data'].get('after')
    if new_after:
        count_words(subreddit, word_list, new_after, counts, processed_words)
    else:
        sorted_counts = sorted(counts.items(), key=lambda x: (-x[1], x[0]))
        for keyword, count in sorted_counts:
            print(f"{keyword}: {count}")
