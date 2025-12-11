window.BENCHMARK_DATA = {
  "lastUpdate": 1765489053979,
  "repoUrl": "https://github.com/GuntramStrecha/zip_view",
  "entries": {
    "C++ Benchmark": [
      {
        "commit": {
          "author": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "committer": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "distinct": true,
          "id": "0da400dc7dae9a77d4758064ae1bb669d096408c",
          "message": "fixup! Add benchmarks to github actions",
          "timestamp": "2025-12-11T17:55:34+01:00",
          "tree_id": "b7283276692604ec67c793bcbbef41df30ad78aa",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/0da400dc7dae9a77d4758064ae1bb669d096408c"
        },
        "date": 1765472261786,
        "tool": "catch2",
        "benches": [
          {
            "name": "std::ranges::views::zip Accumulate",
            "value": 138.197,
            "range": "± 23.5564",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Accumulate",
            "value": 138.731,
            "range": "± 22.4183",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Transform",
            "value": 578.167,
            "range": "± 60.8681",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Transform",
            "value": 566.845,
            "range": "± 73.5245",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Construct",
            "value": 144.633,
            "range": "± 19.8292",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Construct",
            "value": 151.628,
            "range": "± 21.8796",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Iterate",
            "value": 157.512,
            "range": "± 20.5731",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Iterate",
            "value": 141.232,
            "range": "± 22.9613",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      },
      {
        "commit": {
          "author": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "committer": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "distinct": true,
          "id": "bc7b11b7c8f86970b5043b73a0f358b85fc4f256",
          "message": "Simplify min_size function to avoid min_value templates",
          "timestamp": "2025-12-11T18:02:25+01:00",
          "tree_id": "eee1611d6cee63bcabc34085c248e2d21006f370",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/bc7b11b7c8f86970b5043b73a0f358b85fc4f256"
        },
        "date": 1765472679126,
        "tool": "catch2",
        "benches": [
          {
            "name": "std::ranges::views::zip Accumulate",
            "value": 92.4671,
            "range": "± 22.2665",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Accumulate",
            "value": 96.9448,
            "range": "± 22.8182",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Transform",
            "value": 293.24,
            "range": "± 47.6786",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Transform",
            "value": 291.55,
            "range": "± 42.1359",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Construct",
            "value": 88.5148,
            "range": "± 25.4407",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Construct",
            "value": 87.5244,
            "range": "± 24.8601",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Iterate",
            "value": 161.152,
            "range": "± 11.3001",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Iterate",
            "value": 92.7358,
            "range": "± 23.4595",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      },
      {
        "commit": {
          "author": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "committer": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "distinct": true,
          "id": "1bf0ff46335b7edf5831c5a4dacc1d0219cf9891",
          "message": "Simplify min_size function to avoid min_value templates",
          "timestamp": "2025-12-11T18:08:55+01:00",
          "tree_id": "deaf1246494438052e9278b4f6aac87d4a39f87e",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/1bf0ff46335b7edf5831c5a4dacc1d0219cf9891"
        },
        "date": 1765473073042,
        "tool": "catch2",
        "benches": [
          {
            "name": "std::ranges::views::zip Accumulate",
            "value": 85.2467,
            "range": "± 19.3727",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Accumulate",
            "value": 92.6999,
            "range": "± 19.5604",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Transform",
            "value": 249.082,
            "range": "± 67.8187",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Transform",
            "value": 245.502,
            "range": "± 63.6921",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Construct",
            "value": 75.7541,
            "range": "± 13.6048",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Construct",
            "value": 79.0529,
            "range": "± 18.4913",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Iterate",
            "value": 161.596,
            "range": "± 20.1678",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Iterate",
            "value": 88.5161,
            "range": "± 20.2074",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      },
      {
        "commit": {
          "author": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "committer": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "distinct": true,
          "id": "17ef4919454f03d574cceb58d6c3de4d61b45a2c",
          "message": "Simplify min_size function to avoid min_value templates",
          "timestamp": "2025-12-11T18:16:46+01:00",
          "tree_id": "811215706a5cd6ed7616d0e5151c937ccabb4930",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/17ef4919454f03d574cceb58d6c3de4d61b45a2c"
        },
        "date": 1765473780096,
        "tool": "catch2",
        "benches": [
          {
            "name": "std::ranges::views::zip Accumulate",
            "value": 89.3225,
            "range": "± 25.621",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Accumulate",
            "value": 85.7561,
            "range": "± 17.0555",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Transform",
            "value": 249.608,
            "range": "± 63.5858",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Transform",
            "value": 242.685,
            "range": "± 66.1053",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Construct",
            "value": 79.0062,
            "range": "± 28.7912",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Construct",
            "value": 78.2026,
            "range": "± 26.9368",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Iterate",
            "value": 164.021,
            "range": "± 23.5795",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Iterate",
            "value": 87.436,
            "range": "± 20.9622",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      },
      {
        "commit": {
          "author": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "committer": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "distinct": true,
          "id": "69329ba0d7f8011aa9c860bb35192b7723ccd1f0",
          "message": "Remove unused includes",
          "timestamp": "2025-12-11T18:34:35+01:00",
          "tree_id": "88878ea20431142484f39d0371696e9d1933c25d",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/69329ba0d7f8011aa9c860bb35192b7723ccd1f0"
        },
        "date": 1765474607673,
        "tool": "catch2",
        "benches": [
          {
            "name": "std::ranges::views::zip Accumulate",
            "value": 91.7368,
            "range": "± 17.9258",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Accumulate",
            "value": 92.8463,
            "range": "± 19.9433",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Transform",
            "value": 232.383,
            "range": "± 59.3155",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Transform",
            "value": 245.737,
            "range": "± 63.4142",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Construct",
            "value": 79.9591,
            "range": "± 19.5678",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Construct",
            "value": 85.3944,
            "range": "± 15.043",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Iterate",
            "value": 159.682,
            "range": "± 10.6062",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Iterate",
            "value": 88.4868,
            "range": "± 17.8983",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      },
      {
        "commit": {
          "author": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "committer": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "distinct": true,
          "id": "ba98a53b364babe6fd5564f0c27f70c1d3b4b90a",
          "message": "Remove unused includes",
          "timestamp": "2025-12-11T18:38:41+01:00",
          "tree_id": "767a7cb17c98331abf40c57a020b42b98a3c0dfa",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/ba98a53b364babe6fd5564f0c27f70c1d3b4b90a"
        },
        "date": 1765474878727,
        "tool": "catch2",
        "benches": [
          {
            "name": "std::ranges::views::zip Accumulate",
            "value": 88.253,
            "range": "± 17.977",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Accumulate",
            "value": 92.9015,
            "range": "± 15.3555",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Transform",
            "value": 226.277,
            "range": "± 48.5721",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Transform",
            "value": 214.196,
            "range": "± 45.4691",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Construct",
            "value": 73.5107,
            "range": "± 28.0321",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Construct",
            "value": 79.074,
            "range": "± 18.1219",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Iterate",
            "value": 158.8,
            "range": "± 9.82237",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Iterate",
            "value": 88.7742,
            "range": "± 20.0029",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      },
      {
        "commit": {
          "author": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "committer": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "distinct": true,
          "id": "322e7a256e41eb4c1bfd852c5b783961de4eae58",
          "message": "Fix benchmark descriptions",
          "timestamp": "2025-12-11T22:35:31+01:00",
          "tree_id": "a07b063cd6b2b294c3abb763a5309140044c8277",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/322e7a256e41eb4c1bfd852c5b783961de4eae58"
        },
        "date": 1765489053496,
        "tool": "catch2",
        "benches": [
          {
            "name": "std::ranges::views::zip Accumulate",
            "value": 84.9695,
            "range": "± 13.1562",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Accumulate",
            "value": 84.7066,
            "range": "± 12.3408",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Transform",
            "value": 277.568,
            "range": "± 27.3677",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Transform",
            "value": 274.965,
            "range": "± 30.0302",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Construct",
            "value": 81.8365,
            "range": "± 15.9098",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Construct",
            "value": 81.8277,
            "range": "± 23.6342",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Iterate",
            "value": 83.0546,
            "range": "± 11.5848",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Iterate",
            "value": 84.2038,
            "range": "± 11.2162",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      }
    ]
  }
}
